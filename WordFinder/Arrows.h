#pragma once
#include <iostream>
#include "Searcher.h"

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

ref class Arrows
{

public:

	static int up(System::Windows::Forms::TextBox^ textBox1,
		System::Windows::Forms::RichTextBox^ richTextBox1,
		int checkClik,
		int firstIndex) {

		if (textBox1->Text == "" || richTextBox1->Text == "") {
			MessageBox::Show("Введіть текст", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return -1;
		}
		else {
			checkClik--;

			richTextBox1->Select(firstIndex, 0);
			richTextBox1->Focus();

			if (checkClik < 0) {
				checkClik = indexesPositions.size() - 1;
			}

			richTextBox1->SelectionStart = indexesPositions.at(checkClik) + 1;

			return checkClik;
		}
	}

	static int down(System::Windows::Forms::TextBox^ textBox1,
		System::Windows::Forms::RichTextBox^ richTextBox1,
		int checkClik,
		int firstIndex) {

		if (textBox1->Text == "" || richTextBox1->Text == "") {
			MessageBox::Show("Введіть текст", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return -1;
		}
		else {
			checkClik++;

			richTextBox1->Select(firstIndex, 0);
			richTextBox1->Focus();

			if (checkClik >= indexesPositions.size()) {
				checkClik = 0;
			}

			richTextBox1->SelectionStart = indexesPositions.at(checkClik) + 1;

			return checkClik;
		}
	}

	static void beforeArrows(System::Windows::Forms::PictureBox^ pictureBox1,
		System::Windows::Forms::PictureBox^ pictureBox2) {

		pictureBox1->Visible = false;
		pictureBox2->Visible = true;
	}

	static void afterArrows(System::Windows::Forms::PictureBox^ pictureBox1,
		System::Windows::Forms::PictureBox^ pictureBox2) {

		pictureBox1->Visible = true;
		pictureBox2->Visible = false;
	}
};

