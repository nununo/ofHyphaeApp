#version 120
#extension GL_ARB_texture_rectangle : enable

uniform sampler2DRect tex0;
uniform sampler2DRect maskTex;
uniform sampler2DRect conidiaTex;
uniform vec3 maskColor;

void main (void){
  vec2 pos = gl_TexCoord[0].st;

  vec3 hyphae = texture2DRect(tex0, pos).rgb;
  vec3 conidia = texture2DRect(conidiaTex, pos).rgb;
  float mask = texture2DRect(maskTex, pos).a;

  vec3 outColor;
  if (mask == 0) {
    outColor = maskColor;
  } else {
    // If the sum of the parts > 0 it means it's not black so there's something there.
    // Because conidia's alpha is always 1, we'll add the color parts and divide by 3 to determine it.
    float conidiaLight = conidia.r+conidia.g+conidia.b;
    if (conidiaLight > 0) {
      float alpha = conidiaLight/3.0; 
      outColor = hyphae.rgb * (1-alpha) + conidia.rgb;
    } else {
      outColor = hyphae.rgb;
    }
  }

  gl_FragColor = vec4(outColor , 1);
}
