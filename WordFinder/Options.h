#pragma once
#include <iostream>

using namespace System::Windows::Forms;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;
using namespace	System::Windows::Forms;
using namespace	System::Drawing;

ref class Options
{

public:

	static void indexes(System::Windows::Forms::TextBox^ textBox2,
		System::Windows::Forms::ToolStripMenuItem^ indexToolStripMenuItem) {
		if (textBox2->Visible == false)
		{
			textBox2->Visible = true;
			indexToolStripMenuItem->Text = "Індекси - Викл.";
		}
		else
		{
			textBox2->Visible = false;
			indexToolStripMenuItem->Text = "Індекси - Вкл.";
		}
	}

	static void numWords(System::Windows::Forms::Label^ label1,
		System::Windows::Forms::Label^ label2,
		System::Windows::Forms::ToolStripMenuItem^ numWordsToolStripMenuItem) {
		if (label1->Visible == false)
		{
			label1->Visible = true;
			label2->Visible = true;
			numWordsToolStripMenuItem->Text = "Кількість слів - Викл.";
		}
		else
		{
			label1->Visible = false;
			label2->Visible = false;
			numWordsToolStripMenuItem->Text = "Кількість слів - Вкл.";
		}
	}
};

