#include <bits/stdc++.h>
using namespace std;

int main() {
    char tryAgain;
    do {
        system("cls"); // Clear screen (Windows specific)
        // Simple header
        cout << "===================================\n";
        cout << "    PASSWORD STRENGTH CHECKER\n";
        cout << "===================================\n\n";
        string password;
        cout << "Enter your password: ";
        cin >> password;
        // Count different character types
        int upperCount = 0;
        int lowerCount = 0;
        int digitCount = 0;
        int symbolCount = 0;
        for (char c : password) {
            if (isupper(c)) {
                upperCount++;
            } else if (islower(c)) {
                lowerCount++;
            } else if (isdigit(c)) {
                digitCount++;
            } else {
                symbolCount++;
            }
        }

        // Calculate password score
        int score = 0;
        // Base score for length
        if (password.length() >= 8) {
            score += 30;
        } else {
            score += 10;
        }

        // Add points for character variety
        if (upperCount > 0) score += 10;
        if (lowerCount > 0) score += 10;
        if (digitCount > 0) score += 15;
        if (symbolCount > 0) score += 15;

        // Bonus for combinations
        if (upperCount > 0 && digitCount > 0) score += 10;
        if (upperCount > 0 && symbolCount > 0) score += 10;
        if (digitCount > 0 && symbolCount > 0) score += 10;

        // Display results
        cout << "\nPassword Analysis:\n";
        cout << "-----------------------------------\n";
        cout << "Length: " << password.length() << " characters\n";
        cout << "Uppercase letters: " << upperCount << "\n";
        cout << "Lowercase letters: " << lowerCount << "\n";
        cout << "Digits: " << digitCount << "\n";
        cout << "Symbols: " << symbolCount << "\n";
        cout << "-----------------------------------\n";

        // Determine strength
        cout << "Strength: ";
        if (score < 50) {
            cout << "Weak (score: " << score << ")";
        } else if (score < 75) {
            cout << "Average (score: " << score << ")";
        } else if (score < 100) {
            cout << "Strong (score: " << score << ")";
        } else {
            cout << "Very Strong (score: " << score << ")";
        }

        // Give simple feedback
        cout << "\n\nTips to improve your password:\n";
        if (password.length() < 8) {
            cout << "- Make it at least 8 characters long\n";
        }
        if (upperCount == 0) {
            cout << "- Add some uppercase letters\n";
        }
        if (digitCount == 0) {
            cout << "- Add some numbers\n";
        }
        if (symbolCount == 0) {
            cout << "- Add some symbols (!@#$%^&* etc.)\n";
        }

        // Ask to try again
        cout << "\nCheck another password? (y/n): ";
        cin >> tryAgain;

    } while (tryAgain == 'y' || tryAgain == 'Y');
    return 0;
}
