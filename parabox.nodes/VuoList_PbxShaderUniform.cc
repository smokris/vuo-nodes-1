/**
 * @file
 * VuoList implementation.
 *
 * @copyright Copyright © 2012–2015 Kosada Incorporated.
 * This code may be modified and distributed under the terms of the MIT License.
 * For more information, see http://vuo.org/license.
 */

// This module is generated by vuo/type/list/generateVariants.sh.

extern "C" {
#include "VuoHeap.h"
#include "VuoInteger.h"
#include "VuoText.h"
#include "PbxShaderUniform.h"
#include "VuoList_PbxShaderUniform.h"
}
#include "type.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

//@{
/**
 * Ignore calls to VuoRetain and VuoRelease if the element type is not reference-counted.
 */
#if 2 == 0
#define RETAIN(element)
#define RELEASE(element)
#elif 2 == 1
#define RETAIN(element) VuoRetain((void *)element)
#define RELEASE(element) VuoRelease((void *)element)
#elif 2 == 2
#define RETAIN(element) PbxShaderUniform_retain(element)
#define RELEASE(element) PbxShaderUniform_release(element)
#endif
//@}

extern "C" {
/// @{
#ifdef VUO_COMPILER
VuoModuleMetadata({
					 "title" : "List of PbxShaderUniform elements",
					 "description" : "",
					 "keywords" : [ ],
					 "version" : "1.0.0",
					 "dependencies" : [
						"VuoInteger"
					 ]
				 });
#endif
/// @}
}

/**
 * Destroys the list (a VuoList_PbxShaderUniform).
 */
void VuoListDestroy_PbxShaderUniform(void *list);


VuoList_PbxShaderUniform VuoList_PbxShaderUniform_makeFromJson(json_object * js)
{
	VuoList_PbxShaderUniform list = VuoListCreate_PbxShaderUniform();

	if (json_object_get_type(js) == json_type_array)
	{
		int itemCount = json_object_array_length(js);
		for (int i = 0; i < itemCount; ++i)
		{
			json_object *itemObject = json_object_array_get_idx(js, i);
			PbxShaderUniform item = PbxShaderUniform_makeFromJson(itemObject);
			VuoListAppendValue_PbxShaderUniform(list, item);
		}
	}

	return list;
}

json_object * VuoList_PbxShaderUniform_getJson(const VuoList_PbxShaderUniform value)
{
	json_object *listObject = json_object_new_array();

	unsigned long itemCount = VuoListGetCount_PbxShaderUniform(value);
	for (unsigned long i = 1; i <= itemCount; ++i)
	{
		PbxShaderUniform item = VuoListGetValue_PbxShaderUniform(value, i);
		json_object *itemObject = PbxShaderUniform_getJson(item);
		json_object_array_add(listObject, itemObject);
	}

	return listObject;
}

char * VuoList_PbxShaderUniform_getSummary(const VuoList_PbxShaderUniform value)
{
	if (!value)
		return strdup("(empty list)");

	const int maxItems = 20;
	const int maxCharacters = 400;

	unsigned long itemCount = VuoListGetCount_PbxShaderUniform(value);
	if (itemCount == 0)
		return strdup("(empty list)");

	unsigned long characterCount = 0;

	std::ostringstream summary;
	summary << "List containing " << itemCount << " item" << (itemCount == 1 ? "" : "s") << ": <ul>";
	for (unsigned long i = 1; i <= itemCount && i <= maxItems && characterCount <= maxCharacters; ++i)
	{
		PbxShaderUniform item = VuoListGetValue_PbxShaderUniform(value, i);
		std::string itemSummary = PbxShaderUniform_getSummary(item);
		if (itemSummary.length() && itemSummary.find_first_not_of(' ') != std::string::npos)
			summary << "<li>" << itemSummary << "</li>";
		else
			summary << "<li>&nbsp;</li>";
		characterCount += itemSummary.length();
	}

	if (itemCount > maxItems || characterCount > maxCharacters)
		summary << "<li>…</li>";

	summary << "</ul>";

	return strdup(summary.str().c_str());
}

VuoList_PbxShaderUniform VuoListCreate_PbxShaderUniform(void)
{
	std::vector<PbxShaderUniform> * l = new std::vector<PbxShaderUniform>;
	VuoRegister(l, VuoListDestroy_PbxShaderUniform);
	return reinterpret_cast<VuoList_PbxShaderUniform>(l);
}

VuoList_PbxShaderUniform VuoListCopy_PbxShaderUniform(const VuoList_PbxShaderUniform list)
{
	if (!list)
		return NULL;

	std::vector<PbxShaderUniform> *oldList = (std::vector<PbxShaderUniform> *)list;

	std::vector<PbxShaderUniform> *newList = new std::vector<PbxShaderUniform>(*oldList);
	VuoRegister(newList, VuoListDestroy_PbxShaderUniform);

	for (std::vector<PbxShaderUniform>::iterator i = newList->begin(); i != newList->end(); ++i)
		RETAIN(*i);

	return reinterpret_cast<VuoList_PbxShaderUniform>(newList);
}

void VuoListDestroy_PbxShaderUniform(void *list)
{
	if (!list)
		return;

	VuoListRemoveAll_PbxShaderUniform(reinterpret_cast<VuoList_PbxShaderUniform>(list));

	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;
	delete l;
}

PbxShaderUniform VuoListGetValue_PbxShaderUniform(const VuoList_PbxShaderUniform list, const unsigned long index)
{
	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;

	if (!l || l->size() == 0)
		return PbxShaderUniform_makeFromJson(NULL);

	if (index == 0)
		return (*l)[0];

	if (index > l->size())
		return (*l)[l->size()-1];

	return (*l)[index-1];
}

void VuoListSetValue_PbxShaderUniform(const VuoList_PbxShaderUniform list, const PbxShaderUniform value, const unsigned long index)
{
	if (!list)
		return;

	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;

	if (l->size() == 0)
		return;

	unsigned long clampedIndex = index - 1;

	if (index == 0)
		clampedIndex = 0;

	if (index > l->size())
		clampedIndex = l->size() - 1;

	PbxShaderUniform oldValue = (*l)[clampedIndex];
	(*l)[clampedIndex] = value;
	RETAIN(value);
	RELEASE(oldValue);
}

void VuoListInsertValue_PbxShaderUniform(const VuoList_PbxShaderUniform list, const PbxShaderUniform value, const unsigned long index)
{
	if (!list)
		return;

	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;

	unsigned long clampedIndex = index - 1;

	if (index == 0)
		clampedIndex = 0;

	if (index > l->size())
		clampedIndex = l->size() - 1;

	RETAIN(value);
	if (index <= l->size())
		l->insert(l->begin() + clampedIndex, value);
	else
		l->push_back(value);
}

void VuoListPrependValue_PbxShaderUniform(VuoList_PbxShaderUniform list, const PbxShaderUniform value)
{
	if (!list)
		return;

	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;
	RETAIN(value);
	l->insert(l->begin(), value);
}

void VuoListAppendValue_PbxShaderUniform(VuoList_PbxShaderUniform list, const PbxShaderUniform value)
{
	if (!list)
		return;

	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;
	RETAIN(value);
	l->push_back(value);
}

void VuoListExchangeValues_PbxShaderUniform(VuoList_PbxShaderUniform list, const unsigned long indexA, const unsigned long indexB)
{
	if (!list)
		return;

	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;

	size_t size = l->size();
	if (size == 0)
		return;

	unsigned long clampedIndexA = indexA - 1;
	if (indexA == 0)
		clampedIndexA = 0;
	if (indexA > size)
		clampedIndexA = size - 1;

	unsigned long clampedIndexB = indexB - 1;
	if (indexB == 0)
		clampedIndexB = 0;
	if (indexB > size)
		clampedIndexB = size - 1;

	PbxShaderUniform value = (*l)[clampedIndexA];
	(*l)[clampedIndexA] = (*l)[clampedIndexB];
	(*l)[clampedIndexB] = value;
}

void VuoListShuffle_PbxShaderUniform(VuoList_PbxShaderUniform list, const double chaos)
{
	if (!list)
		return;

	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;

	size_t size = l->size();
	if (size == 0)
		return;

	double clampedChaos = MIN(MAX(chaos,0),1);
	for (unsigned long i = 0; i < size * clampedChaos; ++i)
	{
		unsigned long j = VuoInteger_random(i, size-1);
		PbxShaderUniform value = (*l)[i];
		(*l)[i] = (*l)[j];
		(*l)[j] = value;
	}
}

void VuoListReverse_PbxShaderUniform(VuoList_PbxShaderUniform list)
{
	if (!list)
		return;

	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;
	std::reverse(l->begin(), l->end());
}

void VuoListCut_PbxShaderUniform(VuoList_PbxShaderUniform list, const signed long startIndex, const unsigned long itemCount)
{
	if (!list)
		return;

	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;

	size_t size = l->size();
	if (size == 0)
		return;

	signed long clampedStartIndex = startIndex - 1;
	signed long clampedEndIndex = clampedStartIndex + itemCount - 1;

	if (clampedStartIndex < 0)
		clampedStartIndex = 0;
	if (clampedEndIndex >= (signed long)size)
		clampedEndIndex = size - 1;

	if (clampedStartIndex > clampedEndIndex)
	{
		VuoListRemoveAll_PbxShaderUniform(list);
		return;
	}

	while (clampedStartIndex--)
		VuoListRemoveFirstValue_PbxShaderUniform(list);

	while (clampedEndIndex++ < (signed long)size-1)
		VuoListRemoveLastValue_PbxShaderUniform(list);
}

void VuoListRemoveFirstValue_PbxShaderUniform(VuoList_PbxShaderUniform list)
{
	if (!list)
		return;

	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;

	if (!l->size())
		return;

	RELEASE(l->front());
	l->erase(l->begin());
}

void VuoListRemoveLastValue_PbxShaderUniform(VuoList_PbxShaderUniform list)
{
	if (!list)
		return;

	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;

	if (!l->size())
		return;

	RELEASE(l->back());
	l->pop_back();
}

void VuoListRemoveAll_PbxShaderUniform(VuoList_PbxShaderUniform list)
{
	if (!list)
		return;

	while (VuoListGetCount_PbxShaderUniform(list) > 0)
		VuoListRemoveLastValue_PbxShaderUniform(list);
}

void VuoListRemoveValue_PbxShaderUniform(VuoList_PbxShaderUniform list, const unsigned long index)
{
	if (!list)
		return;

	if (index == 0)
		return;

	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;

	size_t size = l->size();
	if (size == 0 || index > size)
		return;

	l->erase(l->begin() + index - 1);
}

unsigned long VuoListGetCount_PbxShaderUniform(const VuoList_PbxShaderUniform list)
{
	if (!list)
		return 0;

	std::vector<PbxShaderUniform> * l = (std::vector<PbxShaderUniform> *)list;
	return l->size();
}
