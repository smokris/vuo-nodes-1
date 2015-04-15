/**
 * @file
 * co.parabox.shader.make.glsl node implementation.
 *
 * @copyright Copyright © 2012–2014 Kosada Incorporated.
 * This code may be modified and distributed under the terms of the MIT License.
 * For more information, see http://vuo.org/license.
 */

#include "node.h"
#include "VuoGlContext.h"
#include <OpenGL/CGLMacro.h>
#include <stdio.h>
#include "PbxShaderUniform.h"
#include "VuoList_PbxShaderUniform.h"

VuoModuleMetadata({
					 "title" : "Make Shader with GLSL",
					 "keywords" : [ "opengl", "scenegraph", "graphics", "fragment", "vertex" ],
					 "version" : "2.1.0",
					 "description": "Creates a Vuo Shader from GLSL source code. \n \nThe following `attribute` variables are provided by the scene renderer to the vertex shader: \n \n- `attribute vec4 position;` — Vertex position \n- `attribute vec4 textureCoordinate;` — UV position \n- `attribute vec4 normal;` — Vertex normal \n- `attribute vec4 tangent;` — Vertex tangent \n- `attribute vec4 bitangent;` — Vertex bitangent \n \nImage and float values may be passed to the fragment shader via the `images` and `floats` list ports.  To access these values in GLSL, use `imageX` and `floatX`, where X is the zero based index. \n \nAs an example, to access the first image in the `images` list in GLSL: \n \n\tuniform sampler2D image0; \n \n The projection and model view matrices are defined as: \n \n- `uniform mat4 projectionMatrix;` \n- `uniform mat4 modelviewMatrix;`",
					 "dependencies" : [
						 "VuoGlContext",
						 "PbxShaderUniform"
						],
					 "node" : {
						  "exampleCompositions" : [ "" ]
					 }
				 });

struct nodeInstanceData
{
	VuoShader shader;
};

struct nodeInstanceData * nodeInstanceInit(
	VuoInputData(VuoText) vertexShader,
	VuoInputData(VuoText) fragmentShader
	)
{
	struct nodeInstanceData * instance = (struct nodeInstanceData *)malloc(sizeof(struct nodeInstanceData));
	VuoRegister(instance, free);

	instance->shader = VuoShader_make("GLSL Shader");
	VuoRetain(instance->shader);

	VuoShader_addSource(instance->shader, VuoMesh_IndividualTriangles, vertexShader, NULL, fragmentShader);

	return instance;
}

void nodeInstanceEvent
(
		VuoInstanceData(struct nodeInstanceData *) instance,
		VuoInputData(VuoText, { "default":
"#version 120														\n\
																	\n\
uniform mat4 projectionMatrix;										\n\
uniform mat4 modelviewMatrix;										\n\
attribute vec4 position;											\n\
attribute vec4 normal;												\n\
attribute vec4 textureCoordinate;									\n\
varying vec4 vertNormal;											\n\
varying vec4 texCoord;												\n\
																	\n\
void main(void)														\n\
{																	\n\
	texCoord = textureCoordinate;									\n\
	vertNormal = normalize(modelviewMatrix * normal);				\n\
	gl_Position = projectionMatrix * modelviewMatrix * position;	\n\
}",
"isCodeEditor":true
			 }) vertexShader,
		VuoInputData(VuoText, {"default":
"#version 120															\n\
																		\n\
uniform vec4 color;														\n\
varying vec4 vertNormal;												\n\
varying vec4 texCoord;													\n\
void main(void)															\n\
{																		\n\
	gl_FragColor = color;												\n\
}",
			"isCodeEditor":true}) fragmentShader,
		VuoInputEvent({"eventBlocking":"none","data":"vertexShader"}) vertexShaderEvent,
		VuoInputEvent({"eventBlocking":"none","data":"fragmentShader"}) fragmentShaderEvent,
		VuoInputData(VuoList_PbxShaderUniform) uniforms,
		VuoOutputData(VuoShader) shader
)
{
	/**
	 *	If the vertex or fragment shader text has changed, reload the shader.
	 *	@todo Maybe verify that the shader has successfully compiled before
	 *	pushing it out?
	 */
	if(fragmentShaderEvent || vertexShaderEvent)
	{
		if((*instance)->shader)
		{
			VuoRelease((*instance)->shader);
		}

		(*instance)->shader = VuoShader_make("GLSL Shader");
		VuoRetain((*instance)->shader);

		VuoShader_addSource((*instance)->shader, VuoMesh_IndividualTriangles, vertexShader, NULL, fragmentShader);
	}

	for(unsigned int i = 0; i < VuoListGetCount_PbxShaderUniform(uniforms); i++)
	{
		PbxShaderUniform_setUniform((*instance)->shader, VuoListGetValue_PbxShaderUniform(uniforms, i+1));
	}

	*shader = (*instance)->shader;
}

void nodeInstanceFini(VuoInstanceData(struct nodeInstanceData *) instance)
{
	VuoRelease((*instance)->shader);
}
