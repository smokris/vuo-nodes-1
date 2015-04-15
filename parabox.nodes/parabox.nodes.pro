TEMPLATE = aux
cache()

NODE_SOURCES += \
	co.parabox.time.get.c \
	co.parabox.file.text.c \
	co.parabox.mesh.get.c \
	co.parabox.mesh.make.c \
	co.parabox.mesh.triangle.c \
	co.parabox.shader.make.graph.c \
	co.parabox.shader.make.glsl.c \
	co.parabox.list.average.c \
	co.parabox.list.bounds.c \
	co.parabox.utility.slider.c \
	co.parabox.event.drop.c \
	co.parabox.shader.make.uniform.c

OTHER_FILES += $$NODE_SOURCES

VUO_FRAMEWORK_PATH = ~/sdk/vuo-1.0.0-sdk/framework
VUO_USER_MODULES_PATH = ~/Library/Application\ Support/Vuo/Modules
QMAKE_PRE_LINK += mkdir -p "$${VUO_USER_MODULES_PATH}"

node.input = NODE_SOURCES
node.output = ${QMAKE_FILE_IN_BASE}.vuonode
node.commands = $${VUO_FRAMEWORK_PATH}/vuo-compile --output ${QMAKE_FILE_OUT} ${QMAKE_FILE_IN} \
	&& zip co.parabox.nodes.vuonode ${QMAKE_FILE_OUT} `basename ${QMAKE_FILE_IN}` \
	&& mkdir -p "$${VUO_USER_MODULES_PATH}"
QMAKE_EXTRA_COMPILERS += node

QMAKE_CLEAN = *.vuonode

## Types

TYPE_SOURCES += \
	PbxShaderUniform.c \
	VuoList_PbxShaderUniform.cc

OTHER_FILES += $$TYPE_SOURCES

HEADERS += \
	PbxShaderUniform.h \
	VuoList_PbxShaderUniform.h

VUO_FRAMEWORK_PATH = ~/sdk/vuo-1.0.0-sdk/framework
VUO_USER_MODULES_PATH = ~/Library/Application\ Support/Vuo/Modules

type.input = TYPE_SOURCES
type.output = ${QMAKE_FILE_IN_BASE}.bc
type.commands = $${VUO_FRAMEWORK_PATH}/vuo-compile --output ${QMAKE_FILE_OUT} ${QMAKE_FILE_IN} \
	&& zip co.parabox.nodes.vuonode ${QMAKE_FILE_OUT} `basename ${QMAKE_FILE_IN_BASE}`.h \
	&& mkdir -p "$${VUO_USER_MODULES_PATH}" \
	&& cp co.parabox.nodes.vuonode "$${VUO_USER_MODULES_PATH}"
QMAKE_EXTRA_COMPILERS += type

QMAKE_CLEAN += *.bc
