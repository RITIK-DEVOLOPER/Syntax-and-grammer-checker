#include <bits/stdc++.h>
#include <fstream>
using namespace std;

// Tokenization Of String
vector<string> Tokens(char str[100])
{

    string temp1;
    vector<string> v;
    char *ptr;
    ptr = strtok(str, "  ");
    while (ptr != NULL)
    {
        temp1 = ptr;
        v.push_back(temp1);
        ptr = strtok(NULL, "  ");
    }
    return v;
}
// Getting last character
char last_letter(vector<string> &v)
{
    int vec_size, size_of_last_let;
    vec_size = v.size();
    size_of_last_let = v[vec_size - 1].size();
    string l = v[vec_size - 1];

    return l[size_of_last_let - 1];
}
// Remove last character in last word
string changed_last_letter(vector<string> &v)
{
    int vec_size, size_of_last_let;
    vec_size = v.size();
    size_of_last_let = v[vec_size - 1].size();
    string l = v[vec_size - 1], new_last_word;
    char t;
    t = l[size_of_last_let - 1];
    for (int i = 0; i < size_of_last_let - 1; i++)
        new_last_word += l[i];
    return new_last_word;
}
// Number of space in a sentence
int no_of_space_count(char str[100])
{
    int space_count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            space_count++;
        }
    }
    return space_count;
}
// Space Rule Checker
bool space_Checker(int spaceCounter, vector<string> sen_word)
{
    int word_count = 0;
    for (int i = 0; i < sen_word.size(); i++)
    {
        word_count++;
    }
    if (spaceCounter == word_count - 1)
    {
        return 1;
    }
    return 0;
}

// Subject Check for singlur subject
bool singular_sub(string s)
{

    bool torch = 0;
    fstream file;
    string t;
    t = "singular subject.txt";
    file.open(t, ios ::in);
    string word;
    file >> word;
    while (!file.eof())
    {
        if (s == word)
        {
            torch = 1;
            break;
        }
        file >> word;
    }
    file.close();
    return torch;
}
// lower case singlarsub checker

bool lowersingular_sub(string s)
{

    bool torch = 0;
    fstream file;
    string t;
    t = "subjectlower.txt";
    file.open(t, ios ::in);
    string word;
    file >> word;
    while (!file.eof())
    {
        if (s == word)
        {
            torch = 1;
            break;
        }
        file >> word;
    }
    file.close();
    return torch;
}
// lower case plural checker

bool lowerplural_sub(string s)
{

    bool torch = 0;
    fstream file;
    string t;
    t = "subjectlower2.txt";
    file.open(t, ios ::in);
    string word;
    file >> word;
    while (!file.eof())
    {
        if (s == word)
        {
            torch = 1;
            break;
        }
        file >> word;
    }
    file.close();
    return torch;
}

// Subject checker for plural sub.
bool plural_sub(string s)
{

    bool torch = 0;
    fstream file;
    string t;
    t = "plural subject.txt";
    file.open(t, ios ::in);
    string word;
    file >> word;
    while (!file.eof())
    {
        if (s == word)
        {
            torch = 1;
            break;
        }
        file >> word;
    }
    file.close();
    return torch;
}

// Verb Check for singlular sub
bool verb1_singular(string s)
{
    bool torch = 0;
    fstream file;
    file.open("verb1_singular.txt", ios ::in);
    string word;
    file >> word;
    while (!file.eof())
    {
        if (s == word)
        {
            torch = 1;
            break;
        }
        file >> word;
    }
    file.close();
    return torch;
}
// Verb check for plural sub.
bool verb1(string s)
{
    bool torch = 0;
    fstream file;
    file.open("verb1.txt", ios ::in);
    string word;
    file >> word;
    while (!file.eof())
    {
        if (s == word)
        {
            torch = 1;
            break;
        }
        file >> word;
    }
    file.close();
    return torch;
}
// Verb check for past siimple
bool verb2(string s)
{
    bool torch = 0;
    fstream file;
    file.open("verb2.txt", ios ::in);
    string word;
    file >> word;
    while (!file.eof())
    {
        if (s == word)
        {
            torch = 1;
            break;
        }
        file >> word;
    }
    file.close();
    return torch;
}
// Verb check for verb3 form
bool verb3(string s)
{
    bool torch = 0;
    fstream file;
    file.open("verb3.txt", ios ::in);
    string word;
    file >> word;
    while (!file.eof())
    {
        if (s == word)
        {
            torch = 1;
            break;
        }
        file >> word;
    }
    file.close();
    return torch;
}
// Verb check for verb4 form
bool verb4(string s)
{
    bool torch = 0;
    fstream file;
    file.open("verb4.txt", ios ::in);
    string word;
    file >> word;
    while (!file.eof())
    {
        if (s == word)
        {
            torch = 1;
            break;
        }
        file >> word;
    }
    file.close();
    return torch;
}

// Object Check
bool object_check(string s)
{
    bool torch = 0;
    fstream file;
    file.open("object.txt", ios ::in);
    string word;
    file >> word;
    while (!file.eof())
    {
        if (s == word)
        {
            torch = 1;
            break;
        }
        file >> word;
    }
    file.close();
    return torch;
}

// Main Function
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char str[100];
    // cout << "Enter the sentense please :\n";
    cin.getline(str, 100);
    int spaceCounter = no_of_space_count(str);
    vector<string> sen_word;
    sen_word = Tokens(str);
    char last = last_letter(sen_word);

    /*
        POSITIVE AND NEGATIVE
    */

    if ((str[0] >= 65 && str[0] <= 90) && (last == '.') && (space_Checker(spaceCounter, sen_word)))
    {
        sen_word[sen_word.size() - 1] = changed_last_letter(sen_word);
        /*--------------------------------------------------INDEFINITE FORM ----------------------------------------------------*/
        // FORMAT OF SIMPLE PRESENT  TENSE
        if ((singular_sub(sen_word[0]) && verb1_singular(sen_word[1]) && object_check(sen_word[2])) || (plural_sub(sen_word[0]) && verb1(sen_word[1]) && object_check(sen_word[2])))
        {
            cout << "SENTENCE IS CORRECT." << endl;
        }
        // Singular Present negative
        else if ((singular_sub(sen_word[0]) && sen_word[1] == "does" && sen_word[2] == "not" && verb1(sen_word[3]) && object_check(sen_word[4])) || (singular_sub(sen_word[0]) && sen_word[1] == "doesn't" && verb1(sen_word[2]) && object_check(sen_word[3])))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Plural Present negative
        else if ((plural_sub(sen_word[0]) && sen_word[1] == "do" && sen_word[2] == "not" && verb1(sen_word[3]) && object_check(sen_word[4])) || (plural_sub(sen_word[0]) && sen_word[1] == "don't" && verb1(sen_word[2]) && object_check(sen_word[3])))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // FORMAT of PAST SIMPLE TENSE (sub + v2 + obj)
        else if ((singular_sub(sen_word[0]) || plural_sub(sen_word[0])) && verb2(sen_word[1]) && object_check(sen_word[2]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Past Negative (sub + didn't/ did not + v1 + obj)
        else if (((singular_sub(sen_word[0]) || plural_sub(sen_word[0])) && sen_word[1] == "did" && sen_word[2] == "not" && verb1(sen_word[3]) && object_check(sen_word[4])) || ((singular_sub(sen_word[0]) || plural_sub(sen_word[0])) && sen_word[1] == "didn't" && verb1(sen_word[2]) && object_check(sen_word[3])))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Future Indifinite (sub + will/shall + v1 + obj)
        else if ((((singular_sub(sen_word[0]) || (sen_word[0] != "We" && sen_word[0] != "I" && plural_sub(sen_word[0]))) && sen_word[1] == "will") || ((sen_word[0] == "We" || sen_word[0] == "I") && sen_word[1] == "shall")) && verb1(sen_word[2]) && object_check(sen_word[3]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Future Ind negative (sub + will/shall + not + v1 + obj)
        else if ((((singular_sub(sen_word[0]) || (sen_word[0] != "We" && sen_word[0] != "I" && plural_sub(sen_word[0]))) && sen_word[1] == "will") || ((sen_word[0] == "We" || sen_word[0] == "I") && sen_word[1] == "shall")) && sen_word[2] == "not" && verb1(sen_word[3]) && object_check(sen_word[4]))
        {

            cout << "SENTENCE IS CORRECT" << endl;
        }
        /*-----------------------------CONTINUOUS FORM------------------------------*/
        // Present affirmative (sub + is/am/are + v4 + obj)
        else if (((singular_sub(sen_word[0]) && sen_word[1] == "is") || (sen_word[0] != "I" && plural_sub(sen_word[0]) && sen_word[1] == "are") || (sen_word[0] == "I" && sen_word[1] == "am")) && verb4(sen_word[2]) && object_check(sen_word[3]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Present negative (sub + is/am/are + not + v4 + obj)
        else if (((singular_sub(sen_word[0]) && sen_word[1] == "is") || (sen_word[0] != "I" && plural_sub(sen_word[0]) && sen_word[1] == "are") || (sen_word[0] == "I" && sen_word[1] == "am")) && sen_word[2] == "not" && verb4(sen_word[3]) && object_check(sen_word[4]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Past affirmative (sub + was/were + v4 + obj)
        else if (((singular_sub(sen_word[0]) && sen_word[1] == "was") || (sen_word[0] != "I" && plural_sub(sen_word[0]) && sen_word[1] == "were") || (sen_word[0] == "I" && sen_word[1] == "was")) && verb4(sen_word[2]) && object_check(sen_word[3]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Past negative (sub + was/were + not + v4 + obj)
        else if (((singular_sub(sen_word[0]) && sen_word[1] == "was") || (sen_word[0] != "I" && plural_sub(sen_word[0]) && sen_word[1] == "were") || (sen_word[0] == "I" && sen_word[1] == "was")) && sen_word[2] == "not" && verb4(sen_word[3]) && object_check(sen_word[4]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Future affirmative (sub + will/shall + be + v4 + obj)
        else if ((((singular_sub(sen_word[0]) || (sen_word[0] != "We" && sen_word[0] != "I" && plural_sub(sen_word[0]))) && sen_word[1] == "will") || ((sen_word[0] == "We" || sen_word[0] == "I") && sen_word[1] == "shall")) && sen_word[2] == "be" && verb4(sen_word[3]) && object_check(sen_word[4]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Future negative (sub + will/shall + not + be + v4 + obj)
        else if ((((singular_sub(sen_word[0]) || (sen_word[0] != "We" && sen_word[0] != "I" && plural_sub(sen_word[0]))) && sen_word[1] == "will") || ((sen_word[0] == "We" || sen_word[0] == "I") && sen_word[1] == "shall")) && sen_word[2] == "not" && sen_word[3] == "be" && verb4(sen_word[4]) && object_check(sen_word[5]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        /*---------------------------------------------------Perfect Form---------------------------------------------------*/
        // Present Affirmative
        else if (((singular_sub(sen_word[0]) && sen_word[1] == "has") || (plural_sub(sen_word[0]) && sen_word[1] == "have")) && verb3(sen_word[2]) && object_check(sen_word[3]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Present Negative
        else if (((singular_sub(sen_word[0]) && sen_word[1] == "has") || (plural_sub(sen_word[0]) && sen_word[1] == "have")) && sen_word[2] == "not" && verb3(sen_word[3]) && object_check(sen_word[4]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Past Affirmative
        else if ((singular_sub(sen_word[0]) || plural_sub(sen_word[0])) && sen_word[1] == "had" && verb3(sen_word[2]) && object_check(sen_word[3]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Past Negative
        else if ((singular_sub(sen_word[0]) || plural_sub(sen_word[0])) && sen_word[1] == "had" && sen_word[2] == "not" && verb3(sen_word[3]) && object_check(sen_word[4]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Future Affirmative
        else if ((((singular_sub(sen_word[0]) || (sen_word[0] != "We" && sen_word[0] != "I" && plural_sub(sen_word[0]))) && sen_word[1] == "will") || ((sen_word[0] == "We" || sen_word[0] == "I") && sen_word[1] == "shall")) && sen_word[2] == "have" && verb3(sen_word[3]) && object_check(sen_word[4]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Future negative
        else if ((((singular_sub(sen_word[0]) || (sen_word[0] != "We" && sen_word[0] != "I" && plural_sub(sen_word[0]))) && sen_word[1] == "will") || ((sen_word[0] == "We" || sen_word[0] == "I") && sen_word[1] == "shall")) && sen_word[2] == "not" && sen_word[3] == "have" && verb3(sen_word[4]) && object_check(sen_word[5]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        /* some modification needed ---------------------------------------------------------------PERFECT CONTINUOUS FORM-----------------------------------------------------------------*/
        // Persent affirmative (sub + have/has + been + v4 + object(opt) + since/for + time)
        else if (((singular_sub(sen_word[0]) && sen_word[1] == "has") || (plural_sub(sen_word[0]) && sen_word[1] == "have")) && sen_word[2] == "been" && verb4(sen_word[3]) && ((object_check(sen_word[4]) && sen_word[5] == "for") || (object_check(sen_word[4]) && sen_word[5] == "since") || sen_word[4] == "for" || sen_word[4] == "since"))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Present Negative (sub + have/has + not + been + v4 + object(opt) + since/for + time)
        else if (((singular_sub(sen_word[0]) && sen_word[1] == "has") || (plural_sub(sen_word[0]) && sen_word[1] == "have")) && sen_word[2] == "not" && sen_word[3] == "been" && verb4(sen_word[4]) && ((object_check(sen_word[5]) && sen_word[6] == "for") || (object_check(sen_word[5]) && sen_word[6] == "since") || sen_word[5] == "for" || sen_word[5] == "since"))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Past Affirmative (sub + had + been + v4 + object(opt) + since/for + time)
        else if (((singular_sub(sen_word[0]) && sen_word[1] == "had") || (plural_sub(sen_word[0]) && sen_word[1] == "had")) && sen_word[2] == "been" && verb4(sen_word[3]) && ((object_check(sen_word[4]) && sen_word[5] == "for") || (object_check(sen_word[4]) && sen_word[5] == "since") || sen_word[4] == "for" || sen_word[4] == "since"))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Past Negative (sub + had + not +  been + v4 + object(opt) + since/for + time)
        else if (((singular_sub(sen_word[0]) && sen_word[1] == "had") || (plural_sub(sen_word[0]) && sen_word[1] == "had")) && sen_word[2] == "not" && sen_word[3] == "been" && verb4(sen_word[4]) && ((object_check(sen_word[5]) && sen_word[6] == "for") || (object_check(sen_word[5]) && sen_word[6] == "since") || sen_word[5] == "for" || sen_word[5] == "since"))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Futur Affirmative (sub + will/shall + have + been + v4 + object(opt) + since/for + time)
        else if ((((singular_sub(sen_word[0]) || (sen_word[0] != "We" && sen_word[0] != "I" && plural_sub(sen_word[0]))) && sen_word[1] == "will") || ((sen_word[0] == "We" || sen_word[0] == "I") && sen_word[1] == "shall")) && sen_word[2] == "have" && sen_word[3] == "been" && verb4(sen_word[4]) && ((object_check(sen_word[5]) && sen_word[6] == "for") || (object_check(sen_word[5]) && sen_word[6] == "since") || sen_word[5] == "for" || sen_word[5] == "since"))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Future Negative (sub + will/shall + have + not + been + v4 + object(opt) + since/for + time)
        else if ((((singular_sub(sen_word[0]) || (sen_word[0] != "We" && sen_word[0] != "I" && plural_sub(sen_word[0]))) && sen_word[1] == "will") || ((sen_word[0] == "We" || sen_word[0] == "I") && sen_word[1] == "shall")) && sen_word[2] == "have" && sen_word[3] == "not" && sen_word[4] == "been" && verb4(sen_word[5]) && ((object_check(sen_word[6]) && sen_word[7] == "for") || (object_check(sen_word[6]) && sen_word[7] == "since") || sen_word[6] == "for" || sen_word[7] == "since"))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        else
        {
            cout << "SENTENSE IS NOT CORRECT" << endl;
        }
    }
    else if ((str[0] >= 65 && str[0] <= 90) && (last == '?') && (space_Checker(spaceCounter, sen_word)))
    {
        sen_word[sen_word.size() - 1] = changed_last_letter(sen_word);

        // present simple interrogative
        if (((sen_word[0] == "Do") && lowerplural_sub(sen_word[1]) && verb1(sen_word[2]) && object_check(sen_word[3])) || (sen_word[0] == "Does" && lowersingular_sub(sen_word[1]) && verb1(sen_word[2]) && object_check(sen_word[3])))
        {
            cout << "SENTENCE IS CORRECT." << endl;
        } // past simple interrogative
        else if ((sen_word[0] == "Did") && (lowerplural_sub(sen_word[1]) || lowersingular_sub(sen_word[1])) && (verb1(sen_word[2])) && object_check(sen_word[3]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        } // future simple interrogative
        else if ((sen_word[0] == "Will") && (lowerplural_sub(sen_word[1]) || lowersingular_sub(sen_word[1])) && (verb1(sen_word[2])) && object_check(sen_word[3]))
        {
            cout << "SENTENSE IS CORRECT" << endl;
        } // present continuos interrogative
        else if ((sen_word[0] == "Am") && (sen_word[1] == "i") && (verb4(sen_word[2])) && object_check(sen_word[3]) || (sen_word[0] == "Are") && (sen_word[1] == "we" || sen_word[1] == "they" || sen_word[1] == "you") && (verb4(sen_word[2])) && object_check(sen_word[3]) || (sen_word[0] == "Is") && (lowersingular_sub(sen_word[1])) && (verb4(sen_word[2])) && object_check(sen_word[3]))
        {
            cout << "SENTENSE IS CORRECT" << endl;
        } // present simple interrogatiev
        else if ((lowersingular_sub(sen_word[1]) && sen_word[0] == "Is") || (sen_word[0] != "i" && lowerplural_sub(sen_word[1]) && sen_word[1] == "Are") || (sen_word[1] == "i" && sen_word[0] == "Am") && sen_word[2] == "not" && verb4(sen_word[3]) && object_check(sen_word[4]))
        {
            cout << "SENTENSE IS CORRECT" << endl;
        } // past continous interrogative
        else if (((sen_word[0] == "Was") && (lowersingular_sub(sen_word[1]))) || ((sen_word[1] == "i") && verb4(sen_word[2]) && object_check(sen_word[3])) || (sen_word[0] == "Were" && (lowerplural_sub(sen_word[1]) && sen_word[1] != "i") && verb4(sen_word[2]) && object_check(sen_word[3])))
        {
            cout << "SENTENSE IS CORRECT " << endl;
        }
        // Future Affirmative interrogative
        else if ((((lowersingular_sub(sen_word[1]) || (sen_word[1] != "we" && sen_word[1] != "i" && lowerplural_sub(sen_word[1]))) && sen_word[0] == "Will") || ((sen_word[1] == "we" || sen_word[1] == "i") && sen_word[0] == "Shall")) && sen_word[2] == "have" && verb3(sen_word[3]) && object_check(sen_word[4]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        }
        // Future negative interrogative
        else if ((((lowersingular_sub(sen_word[1]) || (sen_word[1] != "we" && sen_word[1] != "i" && lowerplural_sub(sen_word[1]))) && sen_word[0] == "Will") || ((sen_word[1] == "we" || sen_word[1] == "i") && sen_word[0] == "Shall")) && sen_word[2] == "not" && sen_word[3] == "have" && verb3(sen_word[4]) && object_check(sen_word[5]))
        {
            cout << "SENTENCE IS CORRECT" << endl;
        } // present perfect continous interrogative
        else if (((lowersingular_sub(sen_word[1]) && sen_word[0] == "Has") || (lowerplural_sub(sen_word[1]) && sen_word[0] == "Have")) && sen_word[2] == "not" && sen_word[3] == "been" && verb4(sen_word[4]) && ((object_check(sen_word[5]) && sen_word[6] == "for")) || (object_check(sen_word[5]) && sen_word[6] == "since") || sen_word[5] == "for" || sen_word[5] == "since")
        {
            cout << "SENTENSEN IS CORRECT";
        }
        else // past negative interrpgative
            if (((lowersingular_sub(sen_word[1]) && sen_word[0] == "Had") || (lowerplural_sub(sen_word[0]) && sen_word[1] == "Had")) && sen_word[2] == "not" && sen_word[3] == "been" && verb4(sen_word[4]) && ((object_check(sen_word[5]) && sen_word[6] == "for") || (object_check(sen_word[5]) && sen_word[6] == "since") || sen_word[5] == "for" || sen_word[5] == "since"))
            {
                cout << "SENTENCE IS CORRECT" << endl;
            }
            // Present Affirmative
            else if (((lowersingular_sub(sen_word[1]) && sen_word[0] == "Has") || (lowerplural_sub(sen_word[1]) && sen_word[0] == "Have")) && verb3(sen_word[2]) && object_check(sen_word[3]))
            {
                cout << "SENTENCE IS CORRECT" << endl;
            }
            // Present Negative
            else if (((lowersingular_sub(sen_word[1]) && sen_word[0] == "Has") || (lowerplural_sub(sen_word[1]) && sen_word[0] == "Have")) && sen_word[2] == "not" && verb3(sen_word[3]) && object_check(sen_word[4]))
            {
                cout << "SENTENCE IS CORRECT" << endl;
            }
            // Past Affirmative
            else if ((lowersingular_sub(sen_word[1]) || lowerplural_sub(sen_word[1])) && sen_word[0] == "Had" && verb3(sen_word[2]) && object_check(sen_word[3]))
            {
                cout << "SENTENCE IS CORRECT" << endl;
            }
            // Futur Affirmative (sub + will/shall + have + been + v4 + object(opt) + since/for + time)
            else if ((((lowersingular_sub(sen_word[1]) || (sen_word[1] != "we" && sen_word[1] != "i" && lowerplural_sub(sen_word[1]))) && sen_word[0] == "Will") || ((sen_word[1] == "we" || sen_word[1] == "i") && sen_word[0] == "Shall")) && sen_word[2] == "have" && sen_word[3] == "been" && verb4(sen_word[4]) && ((object_check(sen_word[5]) && sen_word[6] == "for") || (object_check(sen_word[5]) && sen_word[6] == "since") || sen_word[5] == "for" || sen_word[5] == "since"))
            {
                cout << "SENTENSE IS CORRECT" << endl;
            }
            else
            {
                cout << "SENTENSE IS NOT CORRECT" << endl;
            }
    }
    else

    {
        cout << "Syntically not correct!" << endl;
    }
    return 0;
}
