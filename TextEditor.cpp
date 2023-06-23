#include <iostream>
#include <string>

using namespace std;

class TextEditor {
private:
    string text;
    int cursor;

public:
    TextEditor() {
        text = " ";
        cursor = 0;
    }

    void addText(string txt) {
        text.insert(cursor, txt);
        cursor += txt.length();
    }

    void deleteText(int k) {
        if (k > cursor) {
            k = cursor;
        }
        if (k > 0) {
            text.erase(cursor - k, k);
            cursor -= k;
        }
    }

    void backspace() {
        if (cursor > 0) {
            text.erase(cursor - 1, 1);
            cursor--;
        }
    }

    int findCursor() {
        return cursor;
    }

    void cursorLeft(int k) {
        int move = min(k, cursor);
        cursor -= move;
    }

    void cursorRight(int k) {
        int move = min(k, int(text.length()) - cursor);
        cursor += move;
    }

    string fullText() {
        return text;
    }

    string showText(int k) {
        int remaining = text.length() - cursor;
        int charsToShow = min(k, remaining);
        return text.substr(cursor, charsToShow);
    }
};

int main() {
    TextEditor editor;
    // Example Commands
    cout << "Initial: " << editor.fullText() << endl;

    editor.addText("Hello");
    cout << "After adding 'Hello': " << editor.fullText() << endl;

    editor.backspace();
    cout << "After backspace: " << editor.fullText() << endl;

    editor.cursorLeft(2);
    cout << "After moving cursor left 2 times: " << editor.fullText() << endl;

    editor.deleteText(3);
    cout << "After deleting text: " << editor.fullText() << endl;

    editor.addText("fa");
    cout << "After adding 'fa': " << editor.fullText() << endl;

    editor.cursorRight(3);
    cout << "After moving cursor right 3 times: " << editor.fullText() << endl;

    cout << "Full text: " << editor.fullText() << endl;

    return 0;
}

