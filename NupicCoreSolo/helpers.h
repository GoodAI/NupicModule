// nupic_core_solo_wrapper.h

/*
C++/CLI wrapper that allows to use the nupic_core_solo.dll from the C# program.
DLL is generated from this source file that can be set as an reference in a C# program.
This DLL uses the nupic_core_simple.dll (therefore both DLLs have to be found in the
path by the using application).

Not all functions implemented in the nupic_core_solo are provided through this wrapper yet.
To use more public functions provided by the nupic_core_solo, it is needed
to export them by adding NUPICCOREDLL_API before function declaration in the respective 
*.hpp file and rebuild the DLLs.
*/

#pragma once

#include <msclr\marshal_cppstd.h>
#include <vector>
#include <algorithm>

using namespace System;
using System::IntPtr;
using System::Runtime::InteropServices::Marshal;
using System::Converter;
using namespace System::Collections::Generic;

template<typename T, typename S>
static std::vector<T> marshalAsStdVector(System::Collections::Generic::ICollection<S>^ list)
{
	if (list == nullptr) throw gcnew ArgumentNullException(L"list");
	std::vector<T> result;
	result.reserve(list->Count);
	for each (S elem in list)
		result.push_back(elem);
	return result;
}

template<typename T>
static std::vector<T> marshalArrayAsStdVector(cli::array<T> ^input)
{
	std::vector<T> result(input->Length);
	{
		pin_ptr<T> pin(&input[0]);
		T *first(pin), *last(pin + input->Length);
		std::copy(first, last, result.begin());
	}
	return result;
}