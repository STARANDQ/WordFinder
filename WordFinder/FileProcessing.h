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

ref class FileProcessing
{

    static String^ fileName = "";

public:


    static String^ openFile(System::Windows::Forms::OpenFileDialog^ openFileDialog1,
        System::Windows::Forms::RichTextBox^ richTextBox1) {

        if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
        {
            fileName = openFileDialog1->FileName;
        }

        try {
            StreamReader^ file;
            file = File::OpenText(fileName);
            richTextBox1->Text = file->ReadToEnd();
            file->Close();
            return fileName;
        }
        catch (Exception^ e) {
            MessageBox::Show("Не вдалось відкрити файл", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return "";
        }
    }

    static void saveAsFile(System::Windows::Forms::SaveFileDialog^ saveFileDialog1,
        System::Windows::Forms::RichTextBox^ richTextBox1) {

        if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK && saveFileDialog1->FileName->Length > 0)
        {
            fileName = saveFileDialog1->FileName;
        }

        try {
            StreamWriter^ file = gcnew StreamWriter(fileName);
            file->Write(richTextBox1->Text);
            file->Close();

        }
        catch (Exception^ e) {
            MessageBox::Show("Не вдалось зберегти файл", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    static void saveFile(System::Windows::Forms::SaveFileDialog^ saveFileDialog1,
        System::Windows::Forms::RichTextBox^ richTextBox1) {

        if (fileName == "") {
            if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK && saveFileDialog1->FileName->Length > 0)
            {
                fileName = saveFileDialog1->FileName;
            }

            try {
                StreamWriter^ file = gcnew StreamWriter(fileName);
                file->Write(richTextBox1->Text);
                file->Close();

            }
            catch (Exception^ e) {
                MessageBox::Show("Не вдалось зберегти файл", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        else {
            try {
                StreamWriter^ file = gcnew StreamWriter(fileName);
                file->Write(richTextBox1->Text);
                file->Close();

            }
            catch (Exception^ e) {
                MessageBox::Show("Не вдалось зберегти файл", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    }
};

