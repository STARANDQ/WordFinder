#pragma once
#include <iostream>
#include "cstring"
#include "string"
#include "string.h"
#include <string>
#include <vector>

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

static std::vector<int> indexesPositions;

ref class Searcher
{

private:

	static int indexes = 0;

	static void MarshalString(String^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

public:

	static int checkClik = -1;
	static int firstIndex = 0;

	static void finder(System::Windows::Forms::TextBox^ textBox1,
		System::Windows::Forms::TextBox^ textBox2,
		System::Windows::Forms::RichTextBox^ richTextBox1,
		System::Windows::Forms::Label^  label1) {

		checkClik = -1;

		indexesPositions.clear();

		unsigned int countWords = 0;

		textBox2->Text = "";

		richTextBox1->ForeColor = System::Drawing::Color::Black;

		std::string text = "";
		std::string input = "";

		MarshalString(richTextBox1->Text, text);
		MarshalString(textBox1->Text, input);

		richTextBox1->Select(0, text.length());
		richTextBox1->SelectionColor = Color::Black;

		int i = 0;
		int index_temp = 0;

		bool isCheck = false;

		if (input != "") {
			for (i = text.find(input, i++); i != std::string::npos; i = text.find(input, i + 1)) {
				if ((i - 1) != -1 && (input.length() - 1) != -1) {
					richTextBox1->Select(index_temp, i - 1);
					richTextBox1->SelectionColor = Color::Black;

					countWords++;

					if (!isCheck) {
						if (firstIndex == 0)
						{
							firstIndex = i - 1;
						}
						richTextBox1->Select(i - 1, input.length());
						richTextBox1->SelectionColor = Color::Red;

						isCheck = true;
					}
					else {

						richTextBox1->Select(i, ((i + input.length() - 1)));
						richTextBox1->SelectionColor = Color::Red;
					}

					textBox2->Text += "[" + (i - 1).ToString() + "; " + (i + input.length() - 1) + "] ";

					indexesPositions.push_back(i - 1);

					indexes++;

					index_temp = i + input.length();
				}
			}

			richTextBox1->Select(index_temp, (text.length()));
			richTextBox1->SelectionColor = Color::Black;
		}

		if (countWords == 0) {
			label1->Text = "Немає подібних слів";
		}
		else {
			label1->Text = countWords.ToString();
		}
	}

};

