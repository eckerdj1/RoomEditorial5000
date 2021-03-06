#version 130

uniform mat4 u_modelMatrix;
uniform mat4 u_projMatrix;
uniform mat4 u_lightPos;

in vec4 vs_position;
in vec3 vs_color;
in vec4 vs_normal;

out vec3 fs_color;
out vec3 fs_light;
out vec3 fs_normal;

void main() { 
	fs_color = vs_color;
	fs_normal = normalize((u_modelMatrix * vs_normal).xyz);
	
	//TODO: Calculate a normal vector pointing from the vertex to the light source
	
	vec4 lPos = u_lightPos[3];
	vec3 vPos = (u_modelMatrix * vs_position).xyz;
	fs_light = normalize(lPos.xyz - vPos);
    
    //built-in things to pass down the pipeline
    gl_Position = u_projMatrix * u_modelMatrix * vs_position;
}