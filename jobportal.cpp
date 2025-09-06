#include <iostream>
#include <cstring>
using namespace std;

class Job {
private:
    int jobID;
    char title[100], description[200], companyName[100];
    double salary;

public:
    Job(int id = 0, const char* t = "", const char* d = "", const char* c = "", double s = 0.0) {
        jobID = id;
        strncpy(title, t, 99);
        title[99] = '\0';
        strncpy(description, d, 199);
        description[199] = '\0';
        strncpy(companyName, c, 99);
        companyName[99] = '\0';
        salary = s;
    }

    void displayJob() {
        cout << "Job ID: " << jobID << "\n";
        cout << "Title: " << title << "\n";
        cout << "Description: " << description << "\n";
        cout << "Company Name: " << companyName << "\n";
        cout << "Salary: " << salary << "\n";
    }

    void updateJob(const char* t, const char* d, const char* c, double s) {
        strncpy(title, t, 99);
        title[99] = '\0';
        strncpy(description, d, 199);
        description[199] = '\0';
        strncpy(companyName, c, 99);
        companyName[99] = '\0';
        salary = s;
    }

    int getJobID() {
        return jobID;
    }
};

int main() {
    const int maxJobs = 100;
    Job jobList[maxJobs];
    int jobCount = 0, choice;

    do {
        cout << "\n--- Job Portal System ---\n";
        cout << "1: Add Job\n2: Display Jobs\n3: Update Job\n4: Delete Job\n5: Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                if (jobCount < maxJobs) {
                    int id;
                    char title[100], description[200], companyName[100];
                    double salary;

                    cout << "Enter job ID: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Enter title: ";
                    cin.getline(title, 100);
                    cout << "Enter description: ";
                    cin.getline(description, 200);
                    cout << "Enter company name: ";
                    cin.getline(companyName, 100);
                    cout << "Enter salary: ";
                    cin >> salary;

                    jobList[jobCount++] = Job(id, title, description, companyName, salary);
                    cout << "Job added successfully.\n";
                } else {
                    cout << "Error: Maximum job limit reached!\n";
                }
                break;
            }
            case 2: {
                if (jobCount == 0) {
                    cout << "No jobs available to display.\n";
                } else {
                    for (int i = 0; i < jobCount; ++i) {
                        jobList[i].displayJob();
                    }
                }
                break;
            }
            case 3: {
                if (jobCount == 0) {
                    cout << "No jobs available to update.\n";
                } else {
                    int id, found = 0;
                    cout << "Enter job ID to update: ";
                    cin >> id;
                    cin.ignore();

                    for (int i = 0; i < jobCount; ++i) {
                        if (jobList[i].getJobID() == id) {
                            char title[100], description[200], companyName[100];
                            double salary;

                            cout << "Enter new title: ";
                            cin.getline(title, 100);
                            cout << "Enter new description: ";
                            cin.getline(description, 200);
                            cout << "Enter new company name: ";
                            cin.getline(companyName, 100);
                            cout << "Enter new salary: ";
                            cin >> salary;

                            jobList[i].updateJob(title, description, companyName, salary);
                            cout << "Job updated successfully.\n";
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Error: Job ID not found!\n";
                    }
                }
                break;
            }
            case 4: {
                if (jobCount == 0) {
                    cout << "No jobs available to delete.\n";
                } else {
                    int id, found = 0;
                    cout << "Enter job ID to delete: ";
                    cin >> id;

                    for (int i = 0; i < jobCount; ++i) {
                        if (jobList[i].getJobID() == id) {
                            for (int j = i; j < jobCount - 1; ++j) {
                                jobList[j] = jobList[j + 1];
                            }
                            --jobCount;
                            cout << "Job deleted successfully.\n";
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Error: Job ID not found!\n";
                    }
                }
                break;
            }
            case 5:
                cout << "Exiting Job Portal System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
} 

 
