#version 400 core

in vec2 uvCoordinate;
out vec4 out_color;

uniform sampler2D texture_sampler;
uniform float texture_transparency; // boolean value

void main()
{
	vec4 texture_color = texture(texture_sampler, uvCoordinate);

	// transparency test
	if (texture_color.a < 0.5 && texture_transparency > 0)
	{
		discard;
	}

	out_color = texture_color;
}