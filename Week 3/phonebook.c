#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	string name;
	string number;
}
person;

int main(void)
{
    // string names[] = {"Carter", "David"};
    // string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};

    person people[2];

    people[0].name = "Carter";
    people[0].number = "1+617-495-1000";

    people[1].name = "David";
    people[1].number = "1+949-468-2750";

    for (int i = 0; i < 2; i++)
    {
        // if (strcmp(names[i], "David") == 0)
        if (strcmp(people[i].name, "David") == 0)
        {
            // printf("Found %s\n", numbers[i]);
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
