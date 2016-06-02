#pragma once
#include "stdafx.h"
#include "List.h"

class IO
{
	public:
		static int Main(void);

	private:
		static List list;

		static void AddNewItem();
		static void RemoveItem();
		static void SortList();
		static void PrintList();
		static void BadChoice();
};
