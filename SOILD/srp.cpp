
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Journal {
    string title;
    vector<string> entries;

    explicit Journal(const string &title)
            : title(title) {}

    void add_entry(const string &entry);

    //  This is will break Single Responsibility Principle (SRP) because
    // persistence is a separate concern
    void save(const string &file_name);
};

void Journal::add_entry(const string &entry) {
    static size_t count = 0;
    this->entries.push_back(to_string(count++) + " : " + entry);
}

void Journal::save(const string &file_name) {
    ofstream ofs(file_name);
    for (auto &e: entries) {
        ofs << e << endl;
    }
}

struct PersistenceManager {
    static void save(const Journal &j, const string &filename) {
        ofstream ofs(filename);
        for (auto &s: j.entries)
            ofs << s << endl;
    }
};

int main(int argc, char const *argv[]) {
    Journal journal("Dear Diary");
    journal.add_entry("I ate a bug");
    journal.add_entry("I cried today");

    // journal.save("diary.txt");

    PersistenceManager pm;
    pm.save(journal, "diary.txt");
}