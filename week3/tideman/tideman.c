#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }

            // printf("%i\n", ranks[j]);
        }


        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    // printf("%i", pair_count);
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int n = 0;
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] == preferences[j][i])
            {
                continue;
            }
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[n].winner = i;
                pairs[n].loser = j;
                n++;
            }
            else
            {
                pairs[n].winner = j;
                pairs[n].loser = i;
                n++;
            }
            // printf("%i %i\n", pairs[n-1].winner, pairs[n-1].loser);
        }
    }
    pair_count = n;
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int strengths[pair_count];
    for (int i = 0; i < pair_count; i++)
    {
        strengths[i] = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
    }

    int index[pair_count];
    for (int i = 0; i < pair_count; i++)
    {
        index[i] = i;
    }

    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = i+1; j < pair_count; j++)
        {
            if (strengths[i] < strengths[j])
            {
                int temp1 = strengths[i];
                strengths[i] = strengths[j];
                strengths[j] = temp1;

                int temp2 = index[i];
                index[i] = index[j];
                index[j] = temp2;
            }
        }
    }

    pair temp3;
    for (int i = 0; i < pair_count; i++)
    {
        temp3 = pairs[i];
        pairs[i] = pairs[index[i]];
        pairs[index[i]] = temp3;
    }
    return;
}


// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int locked_source[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        locked_source[i] = 0;
    }
    bool flag = true;
    for (int i = 0; i < pair_count; i++)
    {
        locked_source[pairs[i].winner]++;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked_source[j] != 1)
                {
                    flag = false;
                }
        }
        if (!flag)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }

    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int locked_source[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        locked_source[i] = 0;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        
    }
    return;
}