vec2 toUV(in vec2 coord) {
	return vec2(4. * (2. * coord - iResolution.xy) / min(iResolution.x, iResolution.y));
}

vec3 drawGrid(in vec2 uv)
{
	vec3 color = vec3(0.);

	vec2 cell = fract(uv);
	if(cell.x < fwidth(uv.x)) {
		color = vec3(1.);
	}
	if(cell.y < fwidth(uv.y)) {
		color = vec3(1.);
	}

	if(abs(uv.y) < fwidth(uv.y)) {
		color = vec3(1., 0., 0.);
	}

	if(abs(uv.x) < fwidth(uv.x)) {
		color = vec3(0., 1., 0.);
	}

	return color;
}

// draw segment a->b
float drawSegment(in vec2 p, in vec2 a, in vec2 b, in float width)
{
	float color = 0.;

	vec2 ab = b - a;
	vec2 ap = p - a;

	float proj = clamp(dot(ap, ab) / dot(ab, ab), 0., 1.);
	
	float d = length(proj * ab - ap);

	if(d <= width) {
		color = 1.;
	}

	// color = smoothstep(width, 0.9*width, d);

	return color;
}

float funcSin(in float x)
{
	// return sin(x + iTime);
	return sin(x + 1.);
}

float funcSmoothStep(in float x)
{
	return smoothstep(0., .5, x);
}

float plot(in vec2 uv)
{
	float color = 0.;

	for(float x = 0.; x <= iResolution.x; x+=1.) {
		float xn  = toUV(vec2(x, 0.)).x;
		float xn1 = toUV(vec2(x + 1., 0.)).x;

		// color += drawSegment(vec2(uv), vec2(xn, funcSin(xn)), vec2(xn1, funcSin(xn1)), fwidth(uv.x));
		color += drawSegment(vec2(uv), vec2(xn, funcSmoothStep(xn)), vec2(xn1, funcSmoothStep(xn1)), fwidth(uv.x));
	}

	return clamp(color, 0., 1.);
}

void mainImage(out vec4 fragColor, in vec2 fragCoord) 
{
	vec2 uv = toUV(fragCoord);

	vec3 gridColor = drawGrid(uv);

	vec3 plotColor = vec3(plot(uv), plot(uv), 0.);

	vec3 color = mix(gridColor, plotColor, vec3(.5, .5, .5));

	fragColor = vec4(color, 1.);
}