#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;

    cout << "Welcome to ChatBot! Type 'bye' to exit.\n";

    while (true) {
        cout << "You: ";
        getline(cin, input);

        // Convert input to lowercase (optional for better comparison)

        if (input == "hi" || input == "hello") {
            cout << "Bot: Hello there!\n";
        } else if (input == "how are you") {
            cout << "Bot: I'm just a bot, but I'm doing great!\n";
        } else if (input == "what is your name") {
            cout << "Bot: I'm a simple C++ chatbot.\n";
        } else if (input == "bye") {
            cout << "Bot: Goodbye!\n";
            break;
        } else {
            cout << "Bot: Sorry, I don't understand that.\n";
        }
    }

    return 0;
}
