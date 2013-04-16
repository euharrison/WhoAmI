uniform vec3      iResolution;     // viewport resolution (in pixels)
uniform float     iGlobalTime;     // shader playback time (in seconds)
uniform float     iChannelTime[4]; // channel playback time (in seconds)
uniform vec4      iMouse;          // mouse pixel coords. xy: current (if MLB down), zw: click
uniform sampler2D iChannel0;
uniform sampler2D iChannel1;
uniform sampler2D iChannel2;
uniform sampler2D iChannel3;	   // input channel. XX = 2D/Cube
uniform vec4      iDate;           // (year, month, day, time in seconds)

void main() {
	// gl_Position é uma das saídas padrão de vertex shaders
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	// fragColor é uma das informações que a gente vai passar
	// do vertex shader para o fragment shader
	gl_FrontColor = gl_Color;
	gl_BackColor = gl_Color;
	//v_texCoord3D = gl_MultiTexCoord0.xyz;
	//v_texCoord2D = gl_MultiTexCoord0.xy;
	//gl_TexCoord0 = vec3(gl_Position.xy, 0);
	//gl_TexCoord0 = vec4(gl_Position.xy, 0, 0);
}