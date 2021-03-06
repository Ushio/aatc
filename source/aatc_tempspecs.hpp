/*
The zlib/libpng License
http://opensource.org/licenses/zlib-license.php


Angelscript addon Template Containers
Copyright (c) 2014 Sami Vuorela

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it freely,
subject to the following restrictions:

1.	The origin of this software must not be misrepresented;
You must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

2.	Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3.	This notice may not be removed or altered from any source distribution.


Sami Vuorela
samivuorela@gmail.com
*/



#ifndef _includedh_aatc_tempspecs
#define _includedh_aatc_tempspecs



#include "aatc_shared_tempspec.hpp"
#include "aatc_container_traits.hpp"
//#include "aatc_container_switches.hpp"

#if aatc_CONFIG_USE_ASADDON_SERIALIZER
#include "aatc_serializer.hpp"
#endif



BEGIN_AS_NAMESPACE


/*!\brief Actual class used for template specializations defined in c++.*/
template<class T> class aatc_container_vector_tempspec : public aatc_container_shared_1tp_tempspec<aatc_acit_vector<T>, T>{
public:
	aatc_container_vector_tempspec(){}
	aatc_container_vector_tempspec(const aatc_container_vector_tempspec& other) :
		aatc_container_shared_1tp_tempspec(other)
	{}
	~aatc_container_vector_tempspec(){}

	static aatc_container_vector_tempspec* Factory(){ return new aatc_container_vector_tempspec(); }
	static aatc_container_vector_tempspec* Factory_copy(const aatc_container_vector_tempspec& other){ return new aatc_container_vector_tempspec(other); }
	aatc_container_vector_tempspec& operator=(const aatc_container_vector_tempspec& other){ aatc_container_shared_1tp_tempspec::operator=(other); return *this; }
	aatc_container_vector_tempspec& Swap(aatc_container_vector_tempspec& other){ aatc_container_shared_1tp_tempspec::swap(other); return *this; }
};

/*!\brief Actual class used for template specializations defined in c++.*/
template<class T> class aatc_container_list_tempspec : public aatc_container_shared_1tp_tempspec<aatc_acit_list<T>, T>{
public:
	aatc_container_list_tempspec(){}
	aatc_container_list_tempspec(const aatc_container_list_tempspec& other) :
		aatc_container_shared_1tp_tempspec(other)
	{}
	~aatc_container_list_tempspec(){}

	static aatc_container_list_tempspec* Factory(){ return new aatc_container_list_tempspec(); }
	static aatc_container_list_tempspec* Factory_copy(const aatc_container_list_tempspec& other){ return new aatc_container_list_tempspec(other); }
	aatc_container_list_tempspec& operator=(const aatc_container_list_tempspec& other){ aatc_container_shared_1tp_tempspec::operator=(other); return *this; }
	aatc_container_list_tempspec& Swap(aatc_container_list_tempspec& other){ aatc_container_shared_1tp_tempspec::swap(other); return *this; }

	void Remove(const T& value){
		aatc_errorcheck_container_iterator_safety_version_Increment();
		aatc_container_shared_1tp_tempspec::remove(value);
	}
};

/*!\brief Actual class used for template specializations defined in c++.*/
template<class T> class aatc_container_set_tempspec : public aatc_container_shared_1tp_tempspec<aatc_acit_set<T>, T>{
public:
	aatc_container_set_tempspec(){}
	aatc_container_set_tempspec(const aatc_container_set_tempspec& other) :
		aatc_container_shared_1tp_tempspec(other)
	{}
	~aatc_container_set_tempspec(){}

	static aatc_container_set_tempspec* Factory(){ return new aatc_container_set_tempspec(); }
	static aatc_container_set_tempspec* Factory_copy(const aatc_container_set_tempspec& other){ return new aatc_container_set_tempspec(other); }
	aatc_container_set_tempspec& operator=(const aatc_container_set_tempspec& other){ aatc_container_shared_1tp_tempspec::operator=(other); return *this; }
	aatc_container_set_tempspec& Swap(aatc_container_set_tempspec& other){ aatc_container_shared_1tp_tempspec::swap(other); return *this; }
};

/*!\brief Actual class used for template specializations defined in c++.*/
template<class T> class aatc_container_unordered_set_tempspec : public aatc_container_shared_1tp_tempspec<aatc_acit_unordered_set<T, aatc_functor_hash<T>>, T>{
public:
	aatc_container_unordered_set_tempspec(){}
	aatc_container_unordered_set_tempspec(const aatc_container_unordered_set_tempspec& other) :
		aatc_container_shared_1tp_tempspec(other)
	{}
	~aatc_container_unordered_set_tempspec(){}

	static aatc_container_unordered_set_tempspec* Factory(){ return new aatc_container_unordered_set_tempspec(); }
	static aatc_container_unordered_set_tempspec* Factory_copy(const aatc_container_unordered_set_tempspec& other){ return new aatc_container_unordered_set_tempspec(other); }
	aatc_container_unordered_set_tempspec& operator=(const aatc_container_unordered_set_tempspec& other){ aatc_container_shared_1tp_tempspec::operator=(other); return *this; }
	aatc_container_unordered_set_tempspec& Swap(aatc_container_unordered_set_tempspec& other){ aatc_container_shared_1tp_tempspec::swap(other); return *this; }
};





template<
	class dt_content,
		bool GOTFUNC_EQUALS = 1,
		bool GOTFUNC_LESS = 0,
		bool GOTFUNC_HASH = 1
> void aatc_register_container_tempspec_vector(asIScriptEngine* engine, const char* n_content){
	typedef aatc_container_vector_tempspec<dt_content> dt_container;


#if aatc_CONFIG_USE_ASADDON_SERIALIZER
	aatc_serializer_register_container_shared_1tp_tempspec_helpers<dt_container, aatc_CONTAINERTYPE::VECTOR>(aatc_Get_ELS(engine), n_content);
#endif

	//int r = 0;
	//char textbuf[1000];

	char n_containerTcontentT[1000];
	char n_iterator[1000];
	sprintf_s(n_containerTcontentT, 1000, "%s<%s>", aatc_name_script_container_vector, n_content);
	sprintf_s(n_iterator, 1000, "%s%s<%s>", aatc_name_script_container_vector, aatc_name_script_iterator, n_content);

	dt_container::staticname_container = aatc_name_script_container_vector;
	dt_container::staticname_content = n_content;

	aatc_container_shared_1tp_tempspec_Register<dt_container, dt_content, GOTFUNC_EQUALS, GOTFUNC_LESS, GOTFUNC_HASH, aatc_container_traits_vector>(engine, aatc_name_script_container_vector, n_content);

	//aect_iterator_shared_tempspec<dt_container, dt_content>::Register<aatc_Y, aatc_N>(engine, n_iterator, n_content, n_containerTcontentT);

	//sprintf_s(textbuf, 1000, "%s %s()", n_iterator, aatc_name_script_container_method_begin);
	//r = engine->RegisterObjectMethod(n_containerTcontentT, textbuf, asFunctionPtr(aatc_reghelp_construct_hosted<aect_iterator_shared_tempspec<dt_container, dt_content>, dt_container*>), asCALL_CDECL_OBJLAST); assert(r >= 0);

	//sprintf_s(textbuf, 1000, "void erase(%s)", aatc_name_script_sizetype);
	//r = engine->RegisterObjectMethod(n_containerTcontentT, textbuf, asMETHOD(dt_container, Erase_generic_index<aatc_Y>), asCALL_THISCALL); assert(r >= 0);
}

/*!
Call this to register a template specialization for the list container.<\br>
*/
template<class dt_content, bool GOTFUNC_EQUALS = 1, bool GOTFUNC_LESS = 1, bool GOTFUNC_HASH = 1> void aatc_register_container_tempspec_list(asIScriptEngine* engine, const char* n_content){
	typedef aatc_container_list_tempspec<dt_content> dt_container;

#if aatc_CONFIG_USE_ASADDON_SERIALIZER
	aatc_serializer_register_container_shared_1tp_tempspec_helpers<dt_container, aatc_CONTAINERTYPE::LIST>(aatc_Get_ELS(engine), n_content);
#endif

	int r = 0;
	char textbuf[1000];

	char n_containerTcontentT[1000];
	char n_iterator[1000];
	sprintf_s(n_containerTcontentT, 1000, "%s<%s>", aatc_name_script_container_list, n_content);
	sprintf_s(n_iterator, 1000, "%s%s<%s>", aatc_name_script_container_list, aatc_name_script_iterator, n_content);

	dt_container::staticname_container = aatc_name_script_container_list;
	dt_container::staticname_content = n_content;

	aatc_container_shared_1tp_tempspec_Register<dt_container, dt_content, GOTFUNC_EQUALS, GOTFUNC_LESS, GOTFUNC_HASH, aatc_container_traits_list>(engine, aatc_name_script_container_list, n_content);

	{//container type specific functions
		sprintf_s(textbuf, 1000, "void remove(const %s &in)", n_content);
		r = engine->RegisterObjectMethod(n_containerTcontentT, textbuf, asMETHOD(dt_container, Remove), asCALL_THISCALL); assert(r >= 0);
	}

	//aect_iterator_shared_tempspec<dt_container, dt_content>::Register<aatc_Y, aatc_N>(engine, n_iterator, n_content, n_containerTcontentT);

	//sprintf_s(textbuf, 1000, "%s %s()", n_iterator, aatc_name_script_container_method_begin);
	//r = engine->RegisterObjectMethod(n_containerTcontentT, textbuf, asFunctionPtr(aatc_reghelp_construct_hosted<aect_iterator_shared_tempspec<dt_container, dt_content>, dt_container*>), asCALL_CDECL_OBJLAST); assert(r >= 0);
}

template<class dt_content, bool GOTFUNC_EQUALS = 1, bool GOTFUNC_LESS = 1, bool GOTFUNC_HASH = 1> void aatc_register_container_tempspec_set(asIScriptEngine* engine, const char* n_content){
	typedef aatc_container_set_tempspec<dt_content> dt_container;

#if aatc_CONFIG_USE_ASADDON_SERIALIZER
	aatc_serializer_register_container_shared_1tp_tempspec_helpers<dt_container, aatc_CONTAINERTYPE::SET>(aatc_Get_ELS(engine), n_content);
#endif

	//int r = 0;
	//char textbuf[1000];

	char n_containerTcontentT[1000];
	char n_iterator[1000];
	sprintf_s(n_containerTcontentT, 1000, "%s<%s>", aatc_name_script_container_set, n_content);
	sprintf_s(n_iterator, 1000, "%s%s<%s>", aatc_name_script_container_set, aatc_name_script_iterator, n_content);

	dt_container::staticname_container = aatc_name_script_container_set;
	dt_container::staticname_content = n_content;

	aatc_container_shared_1tp_tempspec_Register<dt_container, dt_content, GOTFUNC_EQUALS, GOTFUNC_LESS, GOTFUNC_HASH, aatc_container_traits_set>
		(engine, aatc_name_script_container_set, n_content);

	//aect_iterator_shared_tempspec<dt_container, dt_content>::Register<aatc_N, aatc_Y>(engine, n_iterator, n_content, n_containerTcontentT);

	//sprintf_s(textbuf, 1000, "%s %s()", n_iterator, aatc_name_script_container_method_begin);
	//r = engine->RegisterObjectMethod(n_containerTcontentT, textbuf, asFunctionPtr(aatc_reghelp_construct_hosted<aect_iterator_shared_tempspec<dt_container, dt_content>, dt_container*>), asCALL_CDECL_OBJLAST); assert(r >= 0);
}

template<class dt_content, bool GOTFUNC_EQUALS = 1, bool GOTFUNC_LESS = 1, bool GOTFUNC_HASH = 1> void aatc_register_container_tempspec_unordered_set(asIScriptEngine* engine, const char* n_content){
	typedef aatc_container_unordered_set_tempspec<dt_content> dt_container;

#if aatc_CONFIG_USE_ASADDON_SERIALIZER
	aatc_serializer_register_container_shared_1tp_tempspec_helpers<dt_container, aatc_CONTAINERTYPE::UNORDERED_SET>(aatc_Get_ELS(engine), n_content);
#endif

	//int r = 0;
	//char textbuf[1000];

	char n_containerTcontentT[1000];
	char n_iterator[1000];
	sprintf_s(n_containerTcontentT, 1000, "%s<%s>", aatc_name_script_container_unordered_set, n_content);
	sprintf_s(n_iterator, 1000, "%s%s<%s>", aatc_name_script_container_unordered_set, aatc_name_script_iterator, n_content);

	dt_container::staticname_container = aatc_name_script_container_unordered_set;
	dt_container::staticname_content = n_content;

	aatc_container_shared_1tp_tempspec_Register<dt_container, dt_content, GOTFUNC_EQUALS, GOTFUNC_LESS, GOTFUNC_HASH, aatc_container_traits_unordered_set>
		(engine, aatc_name_script_container_unordered_set, n_content);

	//aect_iterator_shared_tempspec<dt_container, dt_content>::Register<aatc_N, aatc_Y>(engine, n_iterator, n_content, n_containerTcontentT);

	//sprintf_s(textbuf, 1000, "%s %s()", n_iterator, aatc_name_script_container_method_begin);
	//r = engine->RegisterObjectMethod(n_containerTcontentT, textbuf, asFunctionPtr(aatc_reghelp_construct_hosted<aect_iterator_shared_tempspec<dt_container, dt_content>, dt_container*>), asCALL_CDECL_OBJLAST); assert(r >= 0);
}

template<class T, bool GOTFUNC_EQUALS, bool GOTFUNC_LESS, bool GOTFUNC_HASH> void aatc_reghelp_tempspec_all(asIScriptEngine* engine, const char* n_content){
	aatc_register_container_tempspec_vector<T, GOTFUNC_EQUALS, GOTFUNC_LESS, GOTFUNC_HASH>(engine, n_content);
	aatc_register_container_tempspec_list<T, GOTFUNC_EQUALS, GOTFUNC_LESS, GOTFUNC_HASH>(engine, n_content);
	aatc_register_container_tempspec_set<T, GOTFUNC_EQUALS, GOTFUNC_LESS, GOTFUNC_HASH>(engine, n_content);
	if(GOTFUNC_HASH){
		aatc_register_container_tempspec_unordered_set<T, GOTFUNC_EQUALS, GOTFUNC_LESS, GOTFUNC_HASH>(engine, n_content);
	}
}



END_AS_NAMESPACE
#endif