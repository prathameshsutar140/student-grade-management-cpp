#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>

struct User
{
    char username[30];
    char password[30];
};

class Stud
{
public:
    char owner[30];
    int roll_no;
    char name[50];
    float m1, m2, avg;
    float tt_lec, att_lec, att_per;

    void get(char currentUser[])
    {
        strcpy(owner, currentUser);

        cout << "\nEnter Roll Number : ";
        cin >> roll_no;
        cout << "Enter Name of Student : ";
        cin.get();
        cin.getline(name, 50);
        cout << "Enter Unit Test 1 mark (out of 30) : ";
        cin >> m1;
        cout << "Enter Unit Test 2 mark (out of 30) : ";
        cin >> m2;
        cout << "Enter Total Conducted Lectures : ";
        cin >> tt_lec;
        cout << "Enter Lectures Attended By Student : ";
        cin >> att_lec;

        avg = (m1 + m2) / 2.0;

        if (tt_lec > 0)
            att_per = (att_lec / tt_lec) * 100.0;
        else
            att_per = 0.0;
    }

    void display()
    {
        cout << "\n---------------------------------------------------------------" << endl;
        cout << " Roll No            : " << roll_no << endl;
        cout << " Name               : " << name << endl;
        cout << " UT 1 Mark          : " << m1 << "/30" << endl;
        cout << " UT 2 Mark          : " << m2 << "/30" << endl;
        cout << " UT Average         : " << avg << "/30" << endl;
        cout << " Lectures Attended  : " << att_lec << " / " << tt_lec << endl;
        cout << " Attendance (%)     : " << att_per << "%" << endl;

        if (att_per >= 75.0)
            cout << " Attendance Status  : CLEAR" << endl;
        else
            cout << " Attendance Status  : DEFAULTER (<75%)" << endl;

        if (avg >= 12.0)
            cout << " Academic Performance: SATISFACTORY" << endl;
        else
            cout << " Academic Performance: LOW PERFORMER (<40%)" << endl;
            
        cout << "---------------------------------------------------------------" << endl;
    }
};

void main()
{
    clrscr();
    int authChoice, mainChoice, searchRoll, found, authenticated;
    char currentUser[30], inputPass[30], confirm;
    User u;
    Stud s;

    do
    {
        cout << "\n========================================";
        cout << "\n    WELCOME TO EDU GRADE SYSTEM";
        cout << "\n========================================";
        cout << "\n1. Login";
        cout << "\n2. Create New Account";
        cout << "\n3. Exit System";
        cout << "\nEnter Choice (1-3): ";
        cin >> authChoice;

        authenticated = 0;

        switch (authChoice)
        {
            case 2:
            {
                ofstream userOut("USERS.DAT", ios::binary | ios::app);
                cout << "\n--- CREATE NEW ACCOUNT ---";
                cout << "\nEnter Username: ";
                cin >> u.username;
                cout << "Enter Password: ";
                cin >> u.password;

                userOut.write((char*)&u, sizeof(u));
                userOut.close();

                cout << "\nAccount created successfully! Please login now.";
                getch();
                clrscr();
                break;
            }

            case 1:
            {
                ifstream userIn("USERS.DAT", ios::binary);
                if (!userIn)
                {
                    cout << "\nNo users found! Please create an account first.";
                }
                else
                {
                    cout << "\n--- LOGIN PAGE ---";
                    cout << "\nEnter Username: ";
                    cin >> currentUser;
                    cout << "Enter Password: ";
                    cin >> inputPass;

                    while (userIn.read((char*)&u, sizeof(u)))
                    {
                        if (strcmp(u.username, currentUser) == 0 && strcmp(u.password, inputPass) == 0)
                        {
                            authenticated = 1;
                            break;
                        }
                    }
                    userIn.close();

                    if (!authenticated)
                    {
                        cout << "\nIncorrect Username or Password! Access Denied.";
                    }
                }
                getch();
                clrscr();
                break;
            }

            case 3:
                cout << "\nThank you for using EduGrade System. Goodbye!";
                getch();
                return;

            default:
                cout << "\nInvalid choice! Select 1-3.";
                getch();
                clrscr();
        }

        if (authenticated)
        {
            do
            {
                cout << "\n========================================";
                cout << "\n   EDUGRADE MAIN MENU [ User: " << currentUser << " ]";
                cout << "\n========================================";
                cout << "\n1. Add Student Record";
                cout << "\n2. View My Student Records";
                cout << "\n3. Edit My Student Record by Roll No";
                cout << "\n4. Delete My Student Record by Roll No";
                cout << "\n5. Logout";
                cout << "\nEnter choice (1-5): ";
                cin >> mainChoice;

                switch (mainChoice)
                {
                    case 1:
                    {
                        ofstream outFile("STUDENT.DAT", ios::binary | ios::app);
                        s.get(currentUser);
                        outFile.write((char*)&s, sizeof(s));
                        outFile.close();
                        cout << "\nRecord successfully saved to your profile!";
                        break;
                    }

                    case 2:
                    {
                        ifstream inFile("STUDENT.DAT", ios::binary);
                        if (!inFile)
                        {
                            cout << "\nNo records found in system!";
                        }
                        else
                        {
                            found = 0;
                            cout << "\n================ RECORDS FOR " << currentUser << " ================";
                            while (inFile.read((char*)&s, sizeof(s)))
                            {
                                if (strcmp(s.owner, currentUser) == 0)
                                {
                                    s.display();
                                    found = 1;
                                }
                            }
                            inFile.close();

                            if (!found)
                                cout << "\nNo records found created by user: " << currentUser;
                        }
                        break;
                    }

                    case 3:
                    {
                        fstream file("STUDENT.DAT", ios::binary | ios::in | ios::out);
                        if (!file)
                        {
                            cout << "\nNo records found in system!";
                        }
                        else
                        {
                            found = 0;
                            cout << "\nEnter Roll Number to Edit: ";
                            cin >> searchRoll;

                            while (file.read((char*)&s, sizeof(s)))
                            {
                                if (strcmp(s.owner, currentUser) == 0 && s.roll_no == searchRoll)
                                {
                                    cout << "\nCurrent Record Details:";
                                    s.display();

                                    cout << "\nEnter New Data for Student:\n";
                                    Stud updatedStud;
                                    updatedStud.get(currentUser);

                                    int pos = -1 * (int)sizeof(s);
                                    file.seekp(pos, ios::cur);
                                    file.write((char*)&updatedStud, sizeof(updatedStud));

                                    cout << "\nRecord updated successfully!";
                                    found = 1;
                                    break;
                                }
                            }

                            if (!found)
                                cout << "\nRecord for Roll No " << searchRoll << " not found under your account!";

                            file.close();
                        }
                        break;
                    }

                    case 4:
                    {
                        ifstream inFile("STUDENT.DAT", ios::binary);
                        if (!inFile)
                        {
                            cout << "\nNo records found in system!";
                        }
                        else
                        {
                            found = 0;
                            cout << "\nEnter Roll Number to Delete: ";
                            cin >> searchRoll;

                            while (inFile.read((char*)&s, sizeof(s)))
                            {
                                if (strcmp(s.owner, currentUser) == 0 && s.roll_no == searchRoll)
                                {
                                    found = 1;
                                    cout << "\nRecord Found for Deletion:";
                                    s.display();
                                    break;
                                }
                            }
                            inFile.close();

                            if (!found)
                            {
                                cout << "\nRecord for Roll No " << searchRoll << " not found under your account!";
                            }
                            else
                            {
                                cout << "\nAre you sure you want to delete Roll No " << searchRoll << "? (y/n): ";
                                cin >> confirm;

                                if (confirm == 'y' || confirm == 'Y')
                                {
                                    ifstream sourceFile("STUDENT.DAT", ios::binary);
                                    ofstream tempFile("TEMP.DAT", ios::binary);

                                    while (sourceFile.read((char*)&s, sizeof(s)))
                                    {
                                        if (strcmp(s.owner, currentUser) != 0 || s.roll_no != searchRoll)
                                        {
                                            tempFile.write((char*)&s, sizeof(s));
                                        }
                                    }

                                    sourceFile.close();
                                    tempFile.close();

                                    remove("STUDENT.DAT");
                                    rename("TEMP.DAT", "STUDENT.DAT");

                                    cout << "\nRecord deleted successfully!";
                                }
                                else
                                {
                                    cout << "\nDeletion cancelled!";
                                }
                            }
                        }
                        break;
                    }

                    case 5:
                        cout << "\nLogging out user " << currentUser << "...";
                        break;

                    default:
                        cout << "\nInvalid choice! Select 1-5.";
                }
                getch();
                clrscr();
            } while (mainChoice != 5);
        }

    } while (authChoice != 3);
}