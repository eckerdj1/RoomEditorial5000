#version 130 

in vec3 fs_color;
in vec3 fs_light;
in vec3 fs_normal;
in vec3 halfway;

out vec4 out_Color;

void main() {
    vec3 ambientContrib = fs_color * 0.1;
	vec4 diffuseColor = vec4(fs_color, 1.0);
	vec4 specularColor = vec4(fs_color, 1.0);
	float specExponent = 4.0f;

	//TODO: complete this using the diffuse equation from class!
	float diffuseTerm = clamp(dot(fs_light, fs_normal), 0.0f, 1.0f);

	float specularTerm = pow(max(dot(fs_normal,halfway),0.0f),specExponent);

	//out_Color = diffuseColor;
	
	//TODO: replace above out_Color with below once the diffuse term works.
    out_Color = diffuseTerm * diffuseColor + specularTerm * specularColor + vec4(ambientContrib, 1.0);
}