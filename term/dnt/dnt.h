/// The largest value that the user can set their hours to
#define MAX_HOURS 23
/// The largest value that the user can set their minutes to
#define MAX_MINUTES 59
/// The largest value that the user can set their seconds to
#define MAX_SECONDS 59

/// The largest value that the user can set their year to
#define MAX_YEAR 99
/// The largest value that the user can set their month to
#define MAX_MONTH 12
/// The largest value that the user can set their day to
#define MAX_DAY 31          

/// Minimum year that can be set in memory
#define MIN_YEAR 10
/// Minimum month that can be set in memory
#define MIN_MONTH 1
/// Minimum day that can be set in memory
#define MIN_DAY 1           

/// Unix Epoch year
#define EPOCH_YEAR 1970
/// Unix Epoch first day of the year
#define EPOCH_FIRST_DAY_OF_YEAR 1
/// Unix Epoch first month of the year
#define EPOCH_FIRST_MONTH_OF_YEAR 1
/// Unix Epoch first day of the week in the year
#define EPOCH_FIRST_DAY_OF_WEEK_OF_YEAR 5
/// Number of days in a normal year
#define DAYS_IN_YEAR 365
/// Number of days in a leap year
#define DAYS_IN_LEAP_YEAR 366

/// Minimum value that can be set for hours, minutes, and seconds 
#define MIN 0 

/**
 * Sets the date of the system
 * 
 * Parses the parameter to setdate, breaking the parameter
 * into month, day and year before passing it to
 * setDateInMemory. The basic syntax is month.day.year
 * 
 * @param date The parameter that is passed with setdate. This 
 *             string is parsed and each segment is converted to
 *             a 32-bit int.
 * 
 * @return Returns 1 upon success, -1 upon error
 */
int setdate(char * date);

/**
 * Sets the date in memory
 * 
 * Sets the date in memory by assigning the values to the
 * appropriate places in memory. This method is called by the
 * setdate method.
 * 
 * @param month The month (1 = January ... 12 = December)
 * @param day The day in the month. Can be between 0 and 32
 * @param year The current year. This is a 2-digit number
 * 
 * @return Returns 1 upon success, -1 upon error
*/
int setDateInMemory(int month,int day,int year);

/**
 * Gets the date of the system
 * 
 * Returns a string that represents the current
 * date of the system. This is in the format
 * DayOfWeek, Month Day, Year
 * Ex:      Wednesday, August 25, 2021
 * 
 * @param p Empty paremeter that is required to call this method. Does
 *          not do anything.
 * @return Returns 1 upon success, -1 upon error
*/
int getdate(char * p);

/**
 * Sets the time of the system
 * 
 * Takes the parameter which will be parsed into
 * 32-bit int (later converted to BCD) and sets it into memory.
 * The syntax is Hour.Minute.Second
 * Ex:      10.23.00
 * 
 * @param The parameter passed with the settime call
 * 
 * @return Returns 1 upon success, -1 upon error
*/
int settime(char * time);

/**
 * Sets the time into memory
 * 
 * This method is called by the settime method. Writes the data into memory. First converts 
 * all parameter from 32-bit int to 8-bit BCD and then writes to the appropriate address.
 * 
 * @param hour 32-bit int hour
 * @param minute 32-bit int minute
 * @param second 32-bit int second
*/
void setTimeInMemory(int hour, int minute, int second);

/**
 * Gets the system time
 *
 * Gets the system time from memory by reading from the corresponding
 * memory address. Time will be writtin to the interface in the syntax of
 * Hour:Minute:Second
 * Ex:      10:06:23
 *
 * @param Empty parameter that does not do anything. Required in order to
 *        call from commhand
 * @return Returns 1 upon success, -1 upon error
*/
int gettime(char * p);

/**
 * Converts 32-bit integer to 8-bit BCD
 * 
 * Uses basic arithmetic and bit shifting to convert from 
 * 32-bit integer to 8-bit BCD.
 * 
 * @param value The 32-bit integer that is converted to BCD
 * 
 * @return 8-bit BCD number as an unsigned char
*/
unsigned char ItoBCD(unsigned int value);

/**
 * Converts 8-bit BCD to 32-bit integer
 * 
 * Converts an 8-bit BCD unsigned char to a 
 * 32-bit unsigned integer.
 * 
 * @param value 8-bit BCD value that will be converted to 32-bit int
 * 
 * @return Returns 32-bit unsigned int
*/
unsigned int BCDtoI(unsigned char value);

/**
 * Converts integer to a string month.
 * 
 * Converts a masked integer into an unmasked string
 * month. The months are January to December and are
 * 1 to 12 respectivley.
 * 1 = January
 * 2 = February
 * ...
 * 13 = December
 * 
 * @param value The masked month
 * 
 * @return Returns unmasked string month
*/
char * intToMonth(int value);

/**
 * Converts integer to string day of the week
 * 
 * Converts a masked integer into an unmasked string
 * day of the week. The days of the week are Sunday to 
 * Saturday and are 1 to 7 respectivley.
 * 1 = Sunday
 * 2 = Monday
 * ...
 * 7 = Saturday
 * 
 * @param value The masked integer value of month
 * 
 * @return Returns the unasked string value of month
*/
char * intToDayOfWeek(int value);

/**
 * Converts masked int into string month
 * 
 * Converts the masked integer value of month and
 * converts it into an unmasked string of month
 * 
 * @param value Masked integer month
 * 
 * @return Returns unmasked string of month
*/
char * intToMonth(int value);

/**
 * Calculates the number of days in a month
 * 
 * Calculates the number of days in the month based upon
 * which month it is. If year is divisible by four then it 
 * is a leap year and will add 1 day for February for a
 * total of 29 days. Otherwise, February will be 28 days.
 * 
 * @param month The month in the year (January = 1...December = 12)
 * @param year The year that was being set
 * 
 * @return Returns the number of days in the month
 * 
*/
int daysInMonth(int month, int year);