#include <iostream>
#include <fstream>   // USED FOR FILE HANDLING
#include <iomanip>   // USED FOR ARRANGING AND BEAUTIFYING THE TEXT
#include <cctype>    // CHECKING UPPERCASE LOWERCASE
#include <random>    // FOR GENERATION OF RANDOM INPUTS/ PASSWORDS
#include <chrono>    // FOR TIME CALCULATIONS
#include <algorithm> // FOR PERFORMING SPECIAL FUNCTIONS EASILY LIKE SHUFFLING, Transforming
#include <functional>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <cmath>   // TO APPLY SOME EXPONENT FUNCTIONS
#include <sstream> // TO CONVERT STRING DATA TO (long long) DATA_TYPE [used at line 171]----> stringstream().
#include <string>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(int color)
{
    SetConsoleTextAttribute(hConsole, color);
}
void resetColor()
{
    SetConsoleTextAttribute(hConsole, 7);
}

void printCentered(const string &text)    // TO HELP GUI
{
    cout << "\t\t\t" << text << endl;
}

void printHeader()
{
    system("cls");
    setColor(5); // FOR PURPLE COLOR
    cout << "\n  ▄▄█▀▀▀█▄█████▀███▀▀▀██▄▀████▀  ▀████▀▀███▀▀▀███▀███▀▀▀██▄       ▄▄█▀▀▀█▄█▀███▀   ▀███▀     ██     ▀███▀▀▀██▄ ▀███▀▀▀██▄  ";
    cout << "\n▄██▀     ▀█ ██   ██   ▀██▄ ██      ██    ██    ▀█  ██   ▀██▄    ▄██▀     ▀█ ██       █      ▄██▄      ██   ▀██▄  ██    ▀██▄";
    cout << "\n██▀       ▀ ██   ██   ▄██  ██      ██    ██   █    ██   ▄██     ██▀       ▀ ██       █     ▄█▀██▄     ██   ▄██   ██     ▀██";
    cout << "\n██          ██   ███████   ██████████    ██████    ███████      ██          ██       █    ▄█  ▀██     ███████    ██      ██";
    cout << "\n██▄         ██   ██        ██      ██    ██   █  ▄ ██  ██▄      ██▄    ▀██████       █    ████████    ██  ██▄    ██     ▄██";
    cout << "\n▀██▄     ▄▀ ██   ██        ██      ██    ██     ▄█ ██   ▀██▄    ▀██▄     ██ ██▄     ▄█   █▀      ██   ██   ▀██▄  ██    ▄██▀";
    cout << "\n  ▀▀█████▀▄████▄████▄    ▄████▄  ▄████▄▄██████████████▄ ▄███▄     ▀▀███████  ▀██████▀▀ ▄███▄   ▄████▄████▄ ▄███▄████████▀  \n";
    setColor(14);
}

// _________________________________________________________________________________
// -------------------------------- PASSWORD TOOLS MENU ----------------------------
// _________________________________________________________________________________
void Password_Tools_Menu()
{
    system("cls");
    printHeader();
    setColor(9);
    cout << "\n\n                  PASSWORD TOOLS MENU\n";
    setColor(14);
    cout << "     +--------------------------------------------+\n";
    cout << "     |  [1]  Password Strength Checker            |\n";
    cout << "     |  [2]  Generate Strong Password             |\n";
    cout << "     |  [3]  Encode File                          |\n";
    cout << "     |  [4]  Decode File                          |\n";
    cout << "     |  [5]  Brute Force Simulation               |\n";
    cout << "     |  [0]  Back to Main Menu                    |\n";
    cout << "     +--------------------------------------------+\n\n";
    cout << "        Choice : ";
}

// ____________________________________________________________________________
// -------------------------------- RSA MENU --------------------------------
// ____________________________________________________________________________
void show_RSA_Menu()
{
    system("cls");
    printHeader();
    setColor(9);
    cout << "\n\n            RSA ENCRYPTION MENU\n";
    setColor(14);
    cout << "     +--------------------------------------------+\n";
    cout << "     |  [1]  Encryption [Generate Keys & Encrypt] |\n";
    cout << "     |  [2]  Decryption Only                      |\n";
    cout << "     |  [0]  Back to Main Menu                    |\n";
    cout << "     +--------------------------------------------+\n\n";
    cout << "      Choice : ";
}

// _____________________________________________________________________________
// -------------------------------- MAIN MENU -------------------------------
// ____________________________________________________________________________
void Show_Main_Menu()
{
    system("cls");
    printHeader();
    setColor(9);
    cout << " \n\n                    MAIN MENU\n";
    setColor(14);
    cout << "     +--------------------------------------------+\n";
    cout << "     |  [1]  Password Tools Suite                 |\n";
    cout << "     |  [2]  RSA Encryption Tool                  |\n";
    cout << "     |  [0]  Exit                                 |\n";
    cout << "     +--------------------------------------------+\n\n";
    cout << "     Choice : ";
}

// _________________________________________________________________________________
// -------------------------------- PASSWORD TOOLS FUNCTIONS -----------------------
// _________________________________________________________________________________
bool fileExists(string filename)
{
    ifstream file(filename);
    return file.good();
}

string base64_encode(const string &input)
{
    static const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string ret;
    int i = 0;
    unsigned char arr3[3], arr4[4];
    for (size_t idx = 0; idx < input.size(); idx++)
    {
        arr3[i++] = input[idx];
        if (i == 3)
        {
            arr4[0] = (arr3[0] & 0xfc) >> 2;
            arr4[1] = ((arr3[0] & 0x03) << 4) + ((arr3[1] & 0xf0) >> 4);
            arr4[2] = ((arr3[1] & 0x0f) << 2) + ((arr3[2] & 0xc0) >> 6);
            arr4[3] = arr3[2] & 0x3f;
            for (int j = 0; j < 4; j++)
                ret += chars[arr4[j]];
            i = 0;
        }
    }
    if (i)
    {
        for (int j = i; j < 3; j++)
            arr3[j] = '\0';
        arr4[0] = (arr3[0] & 0xfc) >> 2;
        arr4[1] = ((arr3[0] & 0x03) << 4) + ((arr3[1] & 0xf0) >> 4);
        arr4[2] = ((arr3[1] & 0x0f) << 2) + ((arr3[2] & 0xc0) >> 6);
        for (int j = 0; j < i + 1; j++)
            ret += chars[arr4[j]];
        while (i++ < 3)
            ret += '=';
    }
    return ret;
}

string base64_decode(const string &encoded)
{
    static const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string ret;
    int i = 0;
    unsigned char arr4[4], arr3[3];

    for (size_t idx = 0; idx < encoded.size(); idx++)
    {
        if (encoded[idx] == '=')
            break;
        arr4[i++] = encoded[idx];
        if (i == 4)
        {
            for (i = 0; i < 4; i++)
                arr4[i] = chars.find(arr4[i]);
            arr3[0] = (arr4[0] << 2) + ((arr4[1] & 0x30) >> 4);
            arr3[1] = ((arr4[1] & 0xf) << 4) + ((arr4[2] & 0x3c) >> 2);
            arr3[2] = ((arr4[2] & 0x3) << 6) + arr4[3];
            for (i = 0; i < 3; i++)
                ret += arr3[i];
            i = 0;
        }
    }
    if (i)
    {
        for (int j = i; j < 4; j++)
            arr4[j] = 0;
        for (int j = 0; j < 4; j++)
            arr4[j] = chars.find(arr4[j]);
        arr3[0] = (arr4[0] << 2) + ((arr4[1] & 0x30) >> 4);
        arr3[1] = ((arr4[1] & 0xf) << 4) + ((arr4[2] & 0x3c) >> 2);
        for (int j = 0; j < i - 1; j++)
            ret += arr3[j];
    }
    return ret;
}

string xorCrypt(const string &data, const string &key)
{
    string result = data;
    for (size_t i = 0; i < result.size(); i++)
    {
        result[i] ^= key[i % key.size()];
    }
    return result;
}

bool EncodeFile(const string &inputFile, const string &password)
{
    ifstream in(inputFile, ios::binary);
    if (!in)
    {
        setColor(12);
        cout << "Error: Cannot open file\n";
        resetColor();
        cout<<"Press any key to Continue....";
        getch();
        return false;
    }
    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();

    string Encoded = xorCrypt(content, password);
    string outputFile = inputFile + ".protected";

    ofstream out(outputFile, ios::binary);
    if (!out)
    {
        setColor(12);
        cout << "Error: Cannot create output file\n";
        resetColor();
        cout<<"Press any key to Continue....";
        getch();
        return false;
    }
    out << "******* PROTECTED BY CIPHER GUARD *******\n";
    out << base64_encode(Encoded) << "\n";
    out << "END_PROTECTED\n";
    out.close();
    setColor(10);
    cout << "Success: File Encoded -> " << outputFile << "\n";
    remove(inputFile.c_str());
    resetColor();
    return true;
}

bool Decode_File(const string &inputFile, const string &password)
{
    ifstream in(inputFile);
    if (!in)
    {
        setColor(12);
        cout << "Error: Cannot open file\n";
        resetColor();
        cout<<"Press any key to Continue....";
        getch();
        return false;
    }

    string line, base64Data;
    bool reading = false;
    while (getline(in, line))
    {
        if (line == "******* PROTECTED BY CIPHER GUARD *******")
        {
            reading = true;
            continue;
        }
        if (line == "END_PROTECTED")
            break;
        if (reading)
            base64Data += line;
    }
    in.close();

    if (base64Data.empty())
    {
        setColor(12);
        cout << "Error: Invalid file format\n";
        resetColor();
        cout<<"Press any key to Continue....";
        getch();
        return false;
    }

    string Decoded = xorCrypt(base64_decode(base64Data), password);
    string outputFile = inputFile;
    size_t pos = outputFile.find(".protected");
    if (pos != string::npos)
        outputFile = outputFile.substr(0, pos);
    else
        outputFile += "_Decoded";

    ofstream out(outputFile, ios::binary);
    if (!out)
    {
        setColor(12);
        cout << "Error: Cannot create output file\n";
        resetColor();
        cout<<"Press any key to Continue....";
        getch();
        return false;
    }
    out.write(Decoded.c_str(), Decoded.size());
    out.close();

    setColor(10);
    cout << "Success: File Decoded -> " << outputFile << "\n";
    resetColor();
    cout<<"Press any key to Continue....";
    getch();
    return true;
}

void checkPasswordStrength(const string &password)
{
    int len = password.length();
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (char c : password)
    {
        if (isupper(c))
            hasUpper = true;
        else if (islower(c))
            hasLower = true;
        else if (isdigit(c))
            hasDigit = true;
        else
            hasSpecial = true;
    }

    int score = 0;
    if (len >= 16)
        score += 30;
    else if (len >= 12)
        score += 20;
    else if (len >= 8)
        score += 10;

    if (hasLower)
        score += 15;
    if (hasUpper)
        score += 15;
    if (hasDigit)
        score += 20;
    if (hasSpecial)
        score += 20;

    int types = hasLower + hasUpper + hasDigit + hasSpecial;
    if (types == 4)
        score += 10;

    if (len < 8)
        score -= 20;
    string lower = password;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower.find("password") != string::npos || lower.find("123456") != string::npos)
        score -= 30;
    if (types == 1)
        score -= 15;

    score = max(0, min(100, score));

    setColor(11);
    cout << "\n=== PASSWORD ANALYSIS ===\n";
    resetColor();
    cout << "Length: " << len << " characters\n";
    cout << "Uppercase: " << (hasUpper ? "Yes" : "No") << " | ";
    cout << "Lowercase: " << (hasLower ? "Yes" : "No") << "\n";
    cout << "Numbers: " << (hasDigit ? "Yes" : "No") << " | ";
    cout << "Special: " << (hasSpecial ? "Yes" : "No") << "\n";

    cout << "\nStrength: ";
    if (score >= 80)
    {
        setColor(10);
        cout << "Very Strong";
    }
    else if (score >= 60)
    {
        setColor(11);
        cout << "Strong";
    }
    else if (score >= 40)
    {
        setColor(14);
        cout << "Moderate";
    }
    else
    {
        setColor(12);
        cout << "Weak";
    }
    resetColor();
    cout << " [" << score << "/100]\n";
}

string generatePassword(int length = 12)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string digits = "0123456789";
    const string special = "!@#$%^&*";
    const string all = lower + upper + digits + special;

    random_device rd;
    mt19937 gen(rd());

    string password;
    password += lower[gen() % lower.size()];
    password += upper[gen() % upper.size()];
    password += digits[gen() % digits.size()];
    password += special[gen() % special.size()];

    for (int i = 4; i < length; i++)
    {
        password += all[gen() % all.size()];
    }

    shuffle(password.begin(), password.end(), gen);
    return password;
}

string getHiddenPassword(const string &prompt)
{
    cout << prompt;
    string password;
    char ch;
    while ((ch = getch()) != '\r')
    {
        if (ch == '\b')
        {
            if (!password.empty())
            {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else
        {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

void bruteForceSimulation(const string &target)
{
    system("cls");
    setColor(11);
    cout << "=== BRUTE FORCE SIMULATION ===\n\n";
    resetColor();

    bool hasDigit = false, hasLower = false, hasUpper = false, hasSpecial = false;
    for (char c : target)
    {
        if (isdigit(c))
            hasDigit = true;
        else if (islower(c))
            hasLower = true;
        else if (isupper(c))
            hasUpper = true;
        else
            hasSpecial = true;
    }

    string charset;
    string type;

    if (hasDigit && !hasLower && !hasUpper && !hasSpecial)
    {
        charset = "0123456789";
        type = "Numeric";
    }
    else if ((hasLower || hasUpper) && !hasDigit && !hasSpecial)
    {
        charset = hasLower && hasUpper ? "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" : "abcdefghijklmnopqrstuvwxyz";
        type = hasLower && hasUpper ? "Alphabetic (Mixed)" : "Alphabetic (Lower)";
    }
    else if ((hasLower || hasUpper || hasDigit) && !hasSpecial)
    {
        charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        if (!hasUpper)
            charset = "abcdefghijklmnopqrstuvwxyz0123456789";
        type = "Alphanumeric";
    }
    else
    {
        charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
        type = "Complex";
    }

    setColor(14);
    cout << "Target Length: " << target.length() << "\n";
    cout << "Detected Type: " << type << "\n";
    cout << "Charset Size: " << charset.size() << " characters\n";
    resetColor();

    long long totalCombos = 1;
    for (int i = 0; i < target.length(); ++i)
    {
        totalCombos *= charset.size();
        if (totalCombos > 1e18)
        {
            totalCombos = 1e18;
            break;
        } // prevent overflow display
    }
    cout << "\nTotal Combinations: " << scientific << setprecision(2) << (double)totalCombos << "\n";

    auto start = chrono::high_resolution_clock::now();
    long long attempts = 0;
    bool found = false;

    cout << "\nStarting attack...\n\n";

    static const char spinner[] = {'|', '/', '-', '\\'};
    int spinIdx = 0;

    function<void(string, int)> bruteForce = [&](string current, int depth)
    {
        if (found)
            return;

        if (depth == target.length())
        {
            attempts++;

            if (attempts % 50000 == 0)
            {
                auto now = chrono::high_resolution_clock::now();
                double elapsed = chrono::duration<double>(now - start).count();
                double speed = attempts / max(elapsed, 0.001);

                cout << "\r";
                setColor(14);
                cout << " [" << spinner[spinIdx] << "] ";
                spinIdx = (spinIdx + 1) % 4;
                cout << "Cracking... Attempts: " << attempts
                     << " | Speed: " << fixed << setprecision(0) << speed << " /s"
                     << " | Trying: " << current << string(10, ' ');
                resetColor();
                cout.flush();
            }

            if (current == target)
            {
                found = true;
                auto end = chrono::high_resolution_clock::now();
                double elapsed = chrono::duration<double>(end - start).count();

                cout << "\n\n";
                setColor(10);
                printCentered("+++ PASSWORD CRACKED +++");
                cout << endl;
                printCentered("Password: " + target);
                cout << endl;
                cout << "Time taken: " << fixed << setprecision(3) << elapsed << " seconds\n";
                cout << "Total attempts: " << attempts << "\n\n";
                resetColor();
            }
            return;
        }

        for (char c : charset)
        {
            if (found)
                return;
            bruteForce(current + c, depth + 1);
        }
    };

    bruteForce("", 0);

    if (!found)
    {
        setColor(12);
        cout << "\nPassword not found (simulation limit reached)\n";
        resetColor();
    }
}

void passwordToolsSuite()
{
    while (true)
    {
        Password_Tools_Menu();
        string choice;
        getline(cin, choice);

        if (choice == "1")
        {
            cout << "Enter password: ";
            string password;
            getline(cin, password);
            checkPasswordStrength(password);
        }
        else if (choice == "2")
        {
            cout << "How many passwords? (1-10): ";
            int count = 5;
            if (!(cin >> count))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                count = 5;
            }
            else
            {
                cin.ignore(10000, '\n');
            }
            count = max(1, min(10, count));

            setColor(10);
            cout << "\nGenerated Passwords:\n\n";
            resetColor();
            for (int i = 0; i < count; i++)
            {
                setColor(15);
                cout << "  " << setw(2) << i + 1 << ". ";
                setColor(11);
                cout << generatePassword(12 + i) << endl;
                resetColor();
            }
            cout << endl;
        }
        else if (choice == "3")
        {
            cout << "File path: ";
            string filepath;
            getline(cin, filepath);

            if (!fileExists(filepath))
            {
                setColor(12);
                cout << "File not found!\n";
                resetColor();
            }
            else
            {
                cout << "Password: ";
                string password;
                cin.clear();
                getline(cin, password);
                cout << "Confirm: ";
                string confirm;
                cin.clear();
                getline(cin, confirm);

                if (password != confirm)
                {
                    setColor(12);
                    cout << "Passwords don't match!\n";
                    resetColor();
                }
                else if (password.empty())
                {
                    setColor(12);
                    cout << "Password cannot be empty!\n";
                    resetColor();
                }
                else if (EncodeFile(filepath, password))
                {
                    printCentered("+++ Encoding Successful +++");
                }
            }
        }
        else if (choice == "4")
        {
            cout << "File path (.protected): ";
            string filepath;
            getline(cin, filepath);

            if (!fileExists(filepath))
            {
                setColor(12);
                cout << "File not found!\n";
                resetColor();
            }
            else
            {
                string password;
                cout << "Enter Password: ";
                cin >> password;
                if (Decode_File(filepath, password))
                {
                    remove(filepath.c_str());
                    printCentered("+++ Decoding Successful +++");
                }
            }
        }
        else if (choice == "5")
        {
            cout << "Enter password to crack: ";
            string target;
            getline(cin, target);

            if (target.empty())
                target = "ab12";

            bruteForceSimulation(target);
        }
        else if (choice == "0")
        {
            break;
        }
        else
        {
            setColor(12);
            cout << "Invalid choice!\n";
            resetColor();
        }

        cout << "\n";
        setColor(8);
        cout << "Press ENTER to continue...";
        resetColor();
        cin.get();
    }
}

// _________________________________________________________________________________
// -------------------------------- RSA FUNCTIONS  --------------------------------
// _________________________________________________________________________________

bool isPrime(long long n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (long long i = 5; i * i <= n; i += 6)
    {                                       // THIS IS VERY GOOD METHOD TO GET PRIME IN LESS TIME
        if (n % i == 0 || n % (i + 2) == 0) // IT IS 6K+-1 METHOD
            return false;
    }
    return true;
}

long long modInverse(long long a, long long m)
{
    long long m0 = m, temp, quotient;
    long long x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        quotient = a / m;
        temp = m;
        m = a % m;
        a = temp;
        temp = x0;
        x0 = x1 - quotient * x0;
        x1 = temp;
    }

    if (x1 < 0)
        x1 += m0;
    return x1;
}

long long modPow(long long base, long long exponent, long long mod) // IT COMPUTES  base^exponent % mod ,  The CORE IDEA is to compute (base^exponent) % mod efficiently without actually multiplying base by itself exponent times (which would be too slow for large exponents like 10⁹).

{
    long long result = 1;
    base = base % mod; // THIS REDUCES base value which Prevent OVERFLOW

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exponent = exponent >> 1; // This is equivalent to exponent = exponent / 2
        base = (base * base) % mod;
    }
    return result;
}

long long generatePrime(long long min, long long max)
{
    static int seed = 0; // static means that the value dont change even if it is called again
    seed++;

    for (long long num = max; num >= min; num--)
    {
        if (isPrime(num))
        {
            // Add some randomness by skipping some primes
            if (seed % 3 == 0)
            {
                return num;
            }
            seed++;
        }
    }

    // If no prime found in reverse, search forward
    for (long long num = min; num <= max; num++)
    {
        if (isPrime(num))
        {
            return num;
        }
    }

    // Return default primes if none found
    return 101;
}

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void generate_RSA_Keys(long long &n, long long &e, long long &d, long long p, long long q)
{
    n = p * q;
    long long phi = (p - 1) * (q - 1);

    // Common choices for e
    vector<long long> commonE = {3, 17, 65537};
    e = -1;

    for (long long candidate : commonE)
    {
        if (candidate < phi && gcd(candidate, phi) == 1)
        {
            e = candidate;
            break;
        }
    }

    // If no common e works, find one
    if (e == -1)
    {
        for (e = 2; e < phi; e++)
        {
            if (gcd(e, phi) == 1)
            {
                break;
            }
        }
    }

    // Calculate d (modular inverse of e mod phi)
    d = modInverse(e, phi);
}

vector<long long> encrypt(const string &message, long long e, long long n)
{
    vector<long long> encrypted;
    for (char c : message) // USING FOREACH LOOP
    {
        long long m = static_cast<long long>(c); // CONVERT CHARACTER TO IT'S ASCII VALUE (TYPE_CASTING)
        // Ensure m is within bounds
        if (m >= n)
        { // AS n IS VERY LARGE , THIS RARELY HAPPENS
            m = m % n;
        }
        long long ciphered = modPow(m, e, n); // Now we have ASCII Values , this (modPow) will do RSA.
        encrypted.push_back(ciphered);
    }
    return encrypted;
}

string decrypt(const vector<long long> &encrypted, long long d, long long n)
{
    string decrypted;
    for (long long c : encrypted)
    {
        long long m = modPow(c, d, n); // TIS WILL DO THE DECRYPTION
        decrypted += static_cast<char>(m);
    }
    return decrypted;
}

vector<long long> parseEncryptedMessage(const string &encryptedStr)
{
    vector<long long> encrypted;
    stringstream ss(encryptedStr); // stringstream() is used to convert to convert string data to required data type
    long long num;

    while (ss >> num)
    {
        encrypted.push_back(num);
    }

    return encrypted;
}

void displayVector(const vector<long long> &vec, const string &label)
{
    system("cls");
    printHeader();
    cout << label << ": ";
    setColor(12);
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i != vec.size() - 1)
            cout << " ";
    }
    setColor(14);
    cout << endl;
}

void Encryption_Mode()
{
    system("cls");
    printHeader();
    char choice;
    setColor(2);
    cout << "\n\nChoose an option:\n";
    setColor(14);
    cout << "1. Use Auto-Generated Primes \n";
    cout << "2. Enter your own Prime numbers\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();

    long long p, q, n, e, d;

    if (choice == '1')
    {
        p = generatePrime(350, 4000);
        q = generatePrime(700, 6000);
        while (p == q)
        {
            q = generatePrime(700, 6000);
        }
        cout << "\nGenerated primes: p = " << p << ", q = " << q << "\n";
    }
    else if (choice == '2')
    {
        cout << "\nEnter first prime number (p): ";
        cin >> p;
        cout << "\nEnter second prime number (q): ";
        cin >> q;

        if (!isPrime(p))
        {
            setColor(12);
            cout << "Error: " << p << " is not a prime number\n";
            setColor(14);
            cout << "\nPress any Key to Exit.....";
            getch();
            return;
        }
        if (!isPrime(q))
        {
            setColor(12);
            cout << "Error: " << q << " is not a prime number\n";
            setColor(14);
            cout << "\nPress any Key to Exit.....";
            getch();
            return;
        }
        cin.ignore();
    }
    else
    {
        setColor(12);
        cout << "Invalid choice\n";
        setColor(14);
        cout << "\nPress any Key to Exit.....";
        getch();
        return;
    }

    generate_RSA_Keys(n, e, d, p, q);

    system("cls");
    printHeader();
    cout << "\n==========";
    setColor(5);
    cout << " RSA PARAMETERS";
    setColor(14);
    cout << " ==========\n";
    cout << "p = " << p << "\n";
    cout << "q = " << q << "\n";
    cout << "n = p * q = " << n << "\n";
    cout << "Public exponent (e) = " << e << "\n";
    cout << "Private exponent (d) = " << d << "\n";
    cout << "Public Key: (" << e << ", " << n << ")\n";
    cout << "Private Key: (" << d << ", " << n << ")\n";
    cout << "====================================\n\n";

    char inputChoice;
    setColor(2);
    cout << "\nChoose input method:\n";
    setColor(14);
    cout << "1. Encrypt a FILE\n";
    cout << "2. Encrypt a Typed Messege\n";
    cout << "Choice: ";
    cin >> inputChoice;
    cin.ignore();
    string message;

    if (inputChoice == '1')
    {
        string filename;
        cout << "\nEnter Filename to Encrypt : ";
        getline(cin, filename);

        ifstream inputFile(filename); // ifstream() is used to read data from the file
        if (!inputFile.is_open())
        {
            setColor(12);
            cout << "Error: Could not open file " << filename << "\n";
            setColor(14);
            cout << "\nPress any Key to Exit.....";
            getch();
            return;
        }
        message.assign((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>())); // (istreambuf_iterator<char>(inputFile))------> It reads each single byte one by one from the File
        inputFile.close();                                                                     // (istreambuf_iterator<char>())------> It acts like end of the file to stop it.

        if (message.empty())
        {
            setColor(12);
            cout << "Warning: Input file is empty.\n";
            setColor(14);
            cout << "\nPress any Key to Exit.....";
            getch();
            return;
        }
        cout << "\nFile content loaded (" << message.length() << " characters).\n";
    }
    else if (inputChoice == '2')
    {
        cout << "\nEnter message to Encrypt : ";
        getline(cin, message);
        if (message.empty())
        {
            message = "Hello RSA!";
            cout << "Using default message: " << message << "\n";
        }
    }
    else
    {
        setColor(12);
        cout << "Invalid choice.\n";
        setColor(14);
        cout << "\nPress any Key to Exit.....";
        getch();
        return;
    }

    vector<long long> encrypted = encrypt(message, e, n); // THIS LINE INVOKES THE ENCRYPTION PROCESS.

    // SAVE ENCRYPTED TO FILE.
    ofstream outFile("encrypted.txt");
    for (size_t i = 0; i < encrypted.size(); i++)
    {
        if (i > 0)
            outFile << " ";
        outFile << encrypted[i];
    }
    outFile.close();

    displayVector(encrypted, "\n\nEncrypted message ");
    cout << "\nEncrypted data saved to 'encrypted.txt'\n";
    cout << "\n==========";
    setColor(5);
    cout << " ENCRYPTION ";
    setColor(14);
    cout << "==========\n";
    setColor(2);
    cout << "\nPress any Key to Continue.....";
    setColor(14);
    getch();
}

void decryption_Mode()
{
    system("cls");
    printHeader();
    long long d, n;

    cout << "\n\nEnter Private Key components\n";
    cout << "Private Exponent (d): ";
    cin >> d;
    cout << "Modulus (n): ";
    cin >> n;
    cin.ignore();

    char inputChoice;
    setColor(2);
    cout << "\nChoose Input Method:\n";
    setColor(14);
    cout << "1. Decrypt a FILE\n";
    cout << "2. Decrypt a pasted Ciphertext\n";
    cout << "Choice: ";
    cin >> inputChoice;
    cin.ignore();

    string encryptedStr;

    if (inputChoice == '1')
    {
        string filename;
        cout << "\nEnter Encrypted Filename : ";
        getline(cin, filename);

        ifstream encryptedFile(filename);
        if (!encryptedFile.is_open())
        {
            setColor(12);
            cout << "Error: Could not open file " << filename << "\n";
            setColor(14);
            return;
        }
        encryptedStr.assign((istreambuf_iterator<char>(encryptedFile)), (istreambuf_iterator<char>())); // (istreambuf_iterator<char>(inputFile))------> It reads each single byte one by one from the File
        encryptedFile.close();                                                                          // (istreambuf_iterator<char>())------> It acts like end of the file to stop it.
        if (encryptedStr.empty())
        {
            setColor(12);
            cout << "Error: Encrypted file is empty.\n";
            setColor(14);
            return;
        }
    }
    else if (inputChoice == '2')
    {
        cout << "\nEnter the Encrypted Message\n";
        cout << "Encrypted Message: ";
        getline(cin, encryptedStr);
        if (encryptedStr.empty())
        {
            setColor(12);
            cout << "Error: No input provided.\n";
            setColor(14);
            return;
        }
    }
    else
    {
        setColor(12);
        cout << "Invalid choice.\n";
        setColor(14);
        return;
    }

    vector<long long> encrypted = parseEncryptedMessage(encryptedStr); // IT IS TO CONVERT STRING DATA TO (long long)

    if (encrypted.empty())
    {
        setColor(12); //FOR RED COLOR
        cout << "Error: Could not parse encrypted data. Ensure it contains valid space-separated numbers.\n";
        setColor(14);
        return;
    }

    cout << "\nParsed " << encrypted.size() << " encrypted blocks.\n";

    string decrypted = decrypt(encrypted, d, n);

    // SAVE DECREPTED TO FILE.
    ofstream outFile("decrypted.txt");
    outFile << decrypted;
    outFile.close();

    cout << "\n==========";
    setColor(5);
    cout << " DECRYPTION ";
    setColor(14);
    cout << "==========\n";
    cout << "Decrypted message saved to 'decrypted.txt'\n";
    setColor(12);
    cout << "Preview: ";
    if (decrypted.length() > 100)
    {
        cout << decrypted.substr(0, 100) << " ... [truncated]\n";
    }
    else
    {
        cout << decrypted << "\n";
    }
    setColor(2);
    cout << "\nPress any Key to Continue.....";
    setColor(14);
    getch();
}

void RSA_Encryption_Tool()
{
    while (true)
    {
        show_RSA_Menu();
        string choice;
        getline(cin, choice);

        if (choice == "1")
        {
            Encryption_Mode();
        }
        else if (choice == "2")
        {
            decryption_Mode();
        }
        else if (choice == "0")
        {
            break;
        }
        else
        {
            setColor(12);
            cout << "Invalid choice!\n";
            resetColor();
        }

        cout << "\n";
        setColor(8);
        cout << "Press ENTER to continue...";
        resetColor();
        cin.get();
    }
}

// _________________________________________________________________________________
// -------------------------------- MAIN FUNCTION --------------------------------
// _________________________________________________________________________________
int main()
{
    system("title Security Tool Suite v5.0");
    system("chcp 65001 >nul"); // ESSENTIAL FOR GUI

    while (true)
    {
        Show_Main_Menu();
        string choice;
        getline(cin, choice);

        if (choice == "1")
        {
            passwordToolsSuite();
        }
        else if (choice == "2")
        {
            RSA_Encryption_Tool();
        }
        else if (choice == "0")
        {
            system("cls");
            setColor(10);
            printCentered("Goodbye! Stay Secure!");
            resetColor();
            break;
        }
        else
        {
            setColor(12);
            cout << "Invalid choice!\n";
            resetColor();
            cout << "\nPress ENTER to continue...";
            cin.get();
        }
    }
    return 0;
}