#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Dataset {
    string* columns;
    Dataset* next;
};

int main() {
    Dataset* head = nullptr;
    Dataset* current = nullptr;
    string replace_str = "-";

    ifstream input_file("2023 QS World University Rankings.csv");
    if (!input_file) {
        cerr << "Error opening input file" << endl;
        return 1;
    }

    string header;
    getline(input_file, header);
    stringstream header_stream(header);
    size_t num_columns = 0;
    string column_name;
    while (getline(header_stream, column_name, ',')) {
        num_columns++;
    }

    while (true) {
        string input;
        if (!getline(input_file, input)) {
            break;
        }

        Dataset* new_data = new Dataset;
        new_data->columns = new string[num_columns];
        new_data->next = nullptr;

        size_t start_pos = 0;
        size_t end_pos = input.find(",");
        size_t col_index = 0;
        while (end_pos != string::npos) {
            string column = input.substr(start_pos, end_pos - start_pos);
            if (column.empty()) {
                new_data->columns[col_index] = replace_str;
            }
            else {
                new_data->columns[col_index] = column;
            }
            start_pos = end_pos + 1;
            end_pos = input.find(",", start_pos);
            col_index++;
        }
        string last_column = input.substr(start_pos);
        if (last_column.empty()) {
            new_data->columns[col_index] = replace_str;
        }
        else {
            new_data->columns[col_index] = last_column;
        }

        if (head == nullptr) {
            head = new_data;
            current = new_data;
        }
        else {
            current->next = new_data;
            current = new_data;
        }
    }

    current = head;
    while (current != nullptr) {
        for (size_t i = 0; i < num_columns; i++) {
            string column_value = current->columns[i];
            if (column_value == replace_str) {
                cout << "-\t";
            }
            else {
                cout << column_value << "\t";
            }
        }
        cout << endl;
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        Dataset* next = current->next;
        delete[] current->columns;
        delete current;
        current = next;
    }

    return 0;
}