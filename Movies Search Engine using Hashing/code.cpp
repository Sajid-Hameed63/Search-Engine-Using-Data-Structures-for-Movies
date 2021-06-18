#include <iostream>
#include <fstream>

using namespace std;

// Start oF class Movie
class movie
{
private:
public:
    //constructor of movie class
    string ID;
    float rating;
    int votes;
    float MovieRating;
    movie()
    {
        //ID = nullptr ;
        rating = 0;
        votes = 0;
        MovieRating = 0;
    }

    //getter and setter for the attributes

};
// END OF CLASS MOVIE


// Start of HashClass
class HashClass
{
private:
    int MovieshavingRatingFrom0to1 = 0;
    int MovieshavingRatingFrom1to2 = 0;
    int MovieshavingRatingFrom2to3 = 0;
    int MovieshavingRatingFrom3to4 = 0;
    int MovieshavingRatingFrom4to5 = 0;
    int MovieshavingRatingFrom5to6 = 0;
    int MovieshavingRatingFrom6to7 = 0;
    int MovieshavingRatingFrom7to8 = 0;
    int MovieshavingRatingFrom8to9 = 0;
    int MovieshavingRatingFrom9to10 = 0;
    movie ObjectOfMovieClass[2500];
    int ValueForQuadraticProbing = 0;
    string IdForMostPopularMovie;
    float RatingOfMostPopularMovie = 0;
    string IdForLeastPopularMovie;
    float RatingOfLeastPopularMovie = 1000;
public:
    //start of PreHash function
    int PreHash(int val)
    {
        int i;
        i = val%2500;
        return i;
    }

    //End Of PreHash Function

    // Start of HashFunction
    int HashFunction(int val)
    {
        int l,m,n,o;
        n = ValueForQuadraticProbing*ValueForQuadraticProbing;
        o = val + n;
        m = o%2500;
        if(ObjectOfMovieClass[m].MovieRating == 0)
        {
            ValueForQuadraticProbing = 0;
            return m;
        }
        else if(ObjectOfMovieClass[m].MovieRating != 0)
        {
            ValueForQuadraticProbing++;
            HashFunction(val);
        }
        //return 0;

    }
    // End Of HashFunction

    //Start Of Addition Function
    void addition1(string a,float b,int c,float d,int e)
    {
        ObjectOfMovieClass[e].ID = a;
        ObjectOfMovieClass[e].rating = b;
        ObjectOfMovieClass[e].votes = c;
        ObjectOfMovieClass[e].MovieRating = d;
    }
    //End Of Addition Function


    // Rating Function
    float RatingOfMovie(float rating,int votes)
    {
        float a,b,c,d,e,f;
        a = votes+1000;
        b = votes / a;
        c = b*rating;
        d = 1000/a;
        e = d*7;
        f = c + e;
        return f;
    } // End of RAting Function

    // FUNCTION TO CHECK MOST POPULAR MOVIE
    void PopularMovie()
    {
        cout << "The Most Popular Movie has Id Number = " << IdForMostPopularMovie << endl;
        cout << "The Most Popular Movie has Rating = " << RatingOfMostPopularMovie << endl;
    } // END OF POPULAR MOVIE FUNCION

    // FUNCTION TO CHECK LEAST POPULAR MOVIE
    void LeastMovie()
    {
        cout << "The Least Popular Movie has Id Number = " << IdForLeastPopularMovie << endl;
        cout << "The Least Popular Movie has Rating = " << RatingOfLeastPopularMovie << endl;
    } // END OF LEAST MOVIE FUNCION

    void EqualRatingCal()
    {
        int RatingCheckerForEqualRatingInQuad;
        for(int i=0 ; i<2500 ; i++)
        {
            RatingCheckerForEqualRatingInQuad = ObjectOfMovieClass[i].MovieRating;
            if(RatingCheckerForEqualRatingInQuad == 0 && ObjectOfMovieClass[i].rating != 0)
                MovieshavingRatingFrom0to1++;
            if(RatingCheckerForEqualRatingInQuad == 1)
                MovieshavingRatingFrom1to2++;
            if(RatingCheckerForEqualRatingInQuad == 2)
                MovieshavingRatingFrom2to3++;
            if(RatingCheckerForEqualRatingInQuad == 3)
                MovieshavingRatingFrom3to4++;
            if(RatingCheckerForEqualRatingInQuad == 4)
                MovieshavingRatingFrom4to5++;
            if(RatingCheckerForEqualRatingInQuad == 5)
                MovieshavingRatingFrom5to6++;
            if(RatingCheckerForEqualRatingInQuad == 6)
                MovieshavingRatingFrom6to7++;
            if(RatingCheckerForEqualRatingInQuad == 7)
                MovieshavingRatingFrom7to8++;
            if(RatingCheckerForEqualRatingInQuad == 8)
                MovieshavingRatingFrom8to9++;
            if(RatingCheckerForEqualRatingInQuad == 9)
                MovieshavingRatingFrom9to10++;
        }
    }
    // End of Equal rating function

    //Function to display number of movies having same rating
    void EqualRating()
    {
        EqualRatingCal();
        cout << "Movies Have Rating between 0 to 1 = " << MovieshavingRatingFrom0to1 << endl;
        cout << "Movies Have Rating Between 1 to 2 = " << MovieshavingRatingFrom1to2 << endl;
        cout << "Movies Have Rating Between 2 to 3 = " << MovieshavingRatingFrom2to3 << endl;
        cout << "Movies Have Rating Between 3 to 4 = " << MovieshavingRatingFrom3to4 << endl;
        cout << "Movies Have Rating Between 4 to 5 = " << MovieshavingRatingFrom4to5 << endl;
        cout << "Movies Have Rating Between 5 to 6 = " << MovieshavingRatingFrom5to6 << endl;
        cout << "Movies Have Rating Between 6 to 7 = " << MovieshavingRatingFrom6to7 << endl;
        cout << "Movies Have Rating Between 7 to 8 = " << MovieshavingRatingFrom7to8 << endl;
        cout << "Movies Have Rating Between 8 to 9 = " << MovieshavingRatingFrom8to9 << endl;
        cout << "Movies Have Rating Between 9 to 10 = " << MovieshavingRatingFrom9to10 << endl;
    }
    // END OF EqualRating FUNCTION

    // Start of Load Function
    void load()
    {
        // int ValueOfHashFunctionFromRating;
        long long valueForHashFunction=1;
        long long hashvalueForPreFunction;
        long long hashvalueForFinalFunction;
        string ReceiverForSerialNumber;
        int ReceiverForVotes;
        float ReceiverForRating;
        float RatingChecker;
        ifstream ObjectOfStreamClass;
        ObjectOfStreamClass.open("Data.txt");
        while(ObjectOfStreamClass.eof()==0)
        {
            ObjectOfStreamClass >> ReceiverForSerialNumber;
            ObjectOfStreamClass >> ReceiverForRating;
            ObjectOfStreamClass >> ReceiverForVotes;
            RatingChecker = RatingOfMovie(ReceiverForRating,ReceiverForVotes);
            if(RatingOfMostPopularMovie < RatingChecker)
            {
                RatingOfMostPopularMovie = RatingChecker;
                IdForMostPopularMovie = ReceiverForSerialNumber;
            }

            else if(RatingOfLeastPopularMovie > RatingChecker)
            {
                RatingOfLeastPopularMovie = RatingChecker;
                IdForLeastPopularMovie = ReceiverForSerialNumber;
            }
            hashvalueForPreFunction = PreHash(valueForHashFunction);
            hashvalueForFinalFunction = HashFunction(hashvalueForPreFunction);
            valueForHashFunction++;
            addition1(ReceiverForSerialNumber,ReceiverForRating,ReceiverForVotes,RatingChecker,hashvalueForFinalFunction);
        }
    }  // END OF LOAD DATA FUNCTION

};
//END OF HashClass

int main()
{
    HashClass ObjectOfHashClass;
    ObjectOfHashClass.load();
    ObjectOfHashClass.PopularMovie();
    cout << "---------------------------------------" << endl;
    ObjectOfHashClass.LeastMovie();
    cout << "---------------------------------------" << endl;
    ObjectOfHashClass.EqualRating();
    return 0;
}
