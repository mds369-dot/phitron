function ckYear(year)
{
    if (year % 4 == 0)
    {
        console.log(year + " - This is Leap Year.")
    }
    else
    {
        console.log(year + " - This is not Leap Year.")
    }
}

ckYear(2025)