#version 330 core
out vec4 FragColor;

float near = 0.1;
float far = 100.0;

float LinearizeDepth(float depth){
    float z = depth * 2.0 - 1.0;
    return (2.0 * near * far) / (far + near - z * (far - near));
}

in vec2 TexCoords;

uniform sampler2D texture1;

void main()
{
    float depth = LinearizeDepth(gl_FragCoord.z) / far;
    FragColor = vec4(vec3(depth), 1.0); // set all 4 vector values to 1.0
}