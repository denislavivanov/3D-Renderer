#version 330 core
#define PI 3.141592653

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoords;

out vec2 vTexCoords;

mat4 rotationMatrix(vec3 axis, float angle)
{
    axis = normalize(axis);
    float s = sin(angle);
    float c = cos(angle);
    float oc = 1.0 - c;

    return mat4(oc * axis.x * axis.x + c, oc * axis.x * axis.y - axis.z * s, oc * axis.z * axis.x + axis.y * s, 0.0,
        oc * axis.x * axis.y + axis.z * s, oc * axis.y * axis.y + c, oc * axis.y * axis.z - axis.x * s, 0.0,
        oc * axis.z * axis.x - axis.y * s, oc * axis.y * axis.z + axis.x * s, oc * axis.z * axis.z + c, 0.0,
        0.0, 0.0, 0.0, 1.0);
}

void main()
{
	vTexCoords = aTexCoords;
    //mat4 rotation_mat = rotationMatrix(vec3(0.0f, 1.0f, 0.0f), PI);
    vec4 diff = vec4(0.0f, -0.6f, 0.0f, 0.0f);

	gl_Position = vec4(-0.5f * aPos, 1.0f) + diff;
}