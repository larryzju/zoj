#include <stdio.h>

const int days_nonleap[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int days_leap[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const char week[][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

#define LEAP_DAYS (366)
#define NONLEAP_DAYS (365)

int is_leap_year( int year )
{
    if ( ( year % 4 == 0 && year % 100 != 0 )
        ||
         ( year % 400 == 0 ) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void test()
{
    int i, s = 0;
    for ( i = 1, s = 0; i <= 12; i++ )
    {
        s += days_nonleap[i];
    }
    printf( "nonleap year's day = %d\n", s );

    for ( i = 1, s = 0; i <= 12; i++ )
    {
        s += days_leap[i];
    }
    printf( "leap year's day = %d\n", s );

    const int years[] = {1700, 1800, 1900, 2100, 1600, 2000, 2400};
    for ( i = 0; i < sizeof( years )/sizeof(int); i++ ) 
    {
        printf( "year %d %s leap\n", years[i], (is_leap_year(years[i])==1)?"is":"isn't" );
    }
}

int main()
{
    int days = 0;
    int year = 2000, month = 1, day = 1;
    int day_of_year = 0;
    const int *day_of_month = NULL;
    int m, widx;

    while(1)
    {
        year = 2000; month = 1; day = 1;

        scanf( "%d", &days );
        if ( days == -1 )
        {
            break;
        }

        widx = (6 + days) % 7;

        while( days > 0 )
        {
            if ( is_leap_year( year ) )
            {
                day_of_year = LEAP_DAYS;
                day_of_month = days_leap;
            }
            else
            {
                day_of_year = NONLEAP_DAYS;
                day_of_month = days_nonleap;
            }

            if ( days > day_of_year )
            {
                year++;
                days -= day_of_year;
            }
            else /* days not upto one year */
            {
                for ( m = month; m <= 12; m++ )
                {
                    if ( days > day_of_month[m] )
                    {
                        days -= day_of_month[m];
                        month++;
                    }
                    else
                    {
                        break;
                    }
                }

                day += days;
                days = 0;

                if ( day > day_of_month[m] )
                {
                    day -= day_of_month[m];
                    month++;
                }

                if ( month > 12 )
                {
                    month -= 12;
                    year++;
                }
            }
        }

        printf( "%4d-%02d-%02d %s\n", year, month, day, week[widx] );
    }

    return 0;
}
