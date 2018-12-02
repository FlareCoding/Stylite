#version 400 core

in vec2 vertexPosition;

uniform mat4 transformation_matrix;
uniform mat4 projection_matrix;

void main()
{
	vec4 world_position = projection_matrix * transformation_matrix * vec4(vertexPosition, 0.0, 1.0);
	gl_Position = world_position;
}