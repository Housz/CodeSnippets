#include <openvdb/openvdb.h>

int main()
{
	size_t n = 1 << 5;

	openvdb::initialize();

	openvdb::FloatGrid::Ptr grid =
		openvdb::FloatGrid::create(/*background value=*/);

	openvdb::FloatGrid::Accessor accessor = grid->getAccessor();

	for (uint32_t i = 0; i < n; i++)
	{
		for (uint32_t j = 0; j < n; j++)
		{
			for (uint32_t k = 0; k < n; k++)
			{
				if (i > n/2 && j > n/2)
				{
					openvdb::Coord ijk(i, j, k);
					accessor.setValue(ijk, 2.0);
				}
			}
		}
	}

	grid->setName("mygrid");

	openvdb::GridPtrVec grids;
	grids.push_back(grid);

	openvdb::io::File file("mygrids.vdb");
	file.write(grids);
	file.close();

	return 0;
}