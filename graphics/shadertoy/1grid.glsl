void mainImage(out vec4 fragColor, in vec2 fragCoord) {
	vec2 uv = 5.*(2.*fragCoord - iResolution.xy) / min(iResolution.x, iResolution.y);

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

	fragColor = vec4(color, 1);

}