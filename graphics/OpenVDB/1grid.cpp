#include <openvdb/openvdb.h>
#include <openvdb/tools/LevelSetSphere.h>

template<class GridType>
void
makeSphere(GridType& grid, float radius, const openvdb::Vec3f& c)
{
    using ValueT = typename GridType::ValueType;
    // Distance value for the constant region exterior to the narrow band
    const ValueT outside = grid.background();
    // Distance value for the constant region interior to the narrow band
    // (by convention, the signed distance is negative in the interior of
    // a level set)
    const ValueT inside = -outside;
    // Use the background value as the width in voxels of the narrow band.
    // (The narrow band is centered on the surface of the sphere, which
    // has distance 0.)
    int padding = int(openvdb::math::RoundUp(openvdb::math::Abs(outside)));
    // The bounding box of the narrow band is 2*dim voxels on a side.
    int dim = int(radius + padding);
    // Get a voxel accessor.
    typename GridType::Accessor accessor = grid.getAccessor();
    // Compute the signed distance from the surface of the sphere of each
    // voxel within the bounding box and insert the value into the grid
    // if it is smaller in magnitude than the background value.
    openvdb::Coord ijk;
    int &i = ijk[0], &j = ijk[1], &k = ijk[2];
    for (i = c[0] - dim; i < c[0] + dim; ++i) {
        const float x2 = openvdb::math::Pow2(i - c[0]);
        for (j = c[1] - dim; j < c[1] + dim; ++j) {
            const float x2y2 = openvdb::math::Pow2(j - c[1]) + x2;
            for (k = c[2] - dim; k < c[2] + dim; ++k) {
                // The distance from the sphere surface in voxels
                const float dist = openvdb::math::Sqrt(x2y2
                    + openvdb::math::Pow2(k - c[2])) - radius;
                // Convert the floating-point distance to the grid's value type.
                ValueT val = ValueT(dist);
                // Only insert distances that are smaller in magnitude than
                // the background value.
                if (val < inside || outside < val) continue;
                // Set the distance for voxel (i,j,k).
                accessor.setValue(ijk, val);
            }
        }
    }
    // Propagate the outside/inside sign information from the narrow band
    // throughout the grid.
    openvdb::tools::signedFloodFill(grid.tree());
}

int main()
{
	openvdb::initialize();

	openvdb::FloatGrid::Ptr grid =  openvdb::FloatGrid::create(/*background value=*/2.0);

	makeSphere(*grid, /*radius=*/50.0, /*center=*/openvdb::Vec3f(1.5, 2, 3));
	
	grid->insertMeta("radius", openvdb::FloatMetadata(50.0));

	grid->setTransform(
        openvdb::math::Transform::createLinearTransform(/*voxel size=*/0.5));

	grid->setGridClass(openvdb::GRID_LEVEL_SET);

	grid->setName("LevelSetSphere");

	openvdb::io::File file("mygrids.vdb");

	openvdb::GridPtrVec grids;
	grids.push_back(grid);

	file.write(grids);
    file.close();

	return 0;
}