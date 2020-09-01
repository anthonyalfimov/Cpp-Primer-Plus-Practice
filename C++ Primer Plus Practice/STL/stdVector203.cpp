//
//  STLVector203.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 20/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// std::vector iterators, STL functions and for_each()
//==================================================================================================

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

namespace
{
    struct BookReview
    {
        std::string title;
        int rating;
    };

    bool operator< (const BookReview&, const BookReview&);
    bool isWorseThan (const BookReview&, const BookReview&);

    bool fillBookReview (BookReview&);
    void showBookReview (BookReview&);
}

void showStdVector203()
{
    std::vector<BookReview> bookReviews;        // create an empty vector
    BookReview reviewInput;
    
    while (fillBookReview (reviewInput))
        bookReviews.push_back (reviewInput);
    
    if (bookReviews.size() > 0)
    {
        std::cout << "\nThank you. You entered the following:\nRating\tBook\n";
        std::for_each (bookReviews.begin(), bookReviews.end(), showBookReview);
        
        std::sort (bookReviews.begin(), bookReviews.end());
        std::cout << "\nSorted by title:\nRating\tBook\n";
        std::for_each (bookReviews.begin(), bookReviews.end(), showBookReview);
        
        std::sort (bookReviews.begin(), bookReviews.end(), isWorseThan);
        std::cout << "\nSorted by rating:\nRating\tBook\n";
        std::for_each (bookReviews.begin(), bookReviews.end(), showBookReview);
        
        // std::random_shuffle (bookReviews.begin(), bookReviews.end());    // deprecated
        
        std::random_device rd;      // a uniform random number generator, which gives 'pure randomness'
        std::mt19937 urng (rd());   // a pseudo RNG, which needs to be initialized with a random value
                                    // NOTE: operator() is overloaded for random_device class to
                                    //  advance the engine's state and return the generated value
        std::shuffle (bookReviews.begin(), bookReviews.end(), urng);
        std::cout << "\nRandomly shuffled:\nRating\tBook\n";
        std::for_each (bookReviews.begin(), bookReviews.end(), showBookReview);
    }
    else
        std::cout << "No entries.\n";
    
    std::cout << "\nDone.\n";
}

namespace
{
    bool operator< (const BookReview& r1, const BookReview& r2)
    {
        if (r1.title < r2.title)
            return true;
        
        if (r1.title == r2.title && r1.rating < r2.rating)
            return true;
        
        return false;
    }

    bool isWorseThan (const BookReview& r1, const BookReview& r2)
    {
        if (r1.rating < r2.rating)
            return true;
        
        return false;
    }

    bool fillBookReview (BookReview& br)
    {
        std::cout << "Enter book title (\"quit\" to quit): ";
        std::getline (std::cin, br.title);
        
        if (br.title == "quit")
            return false;
        
        std::cout << "Enger book rating: ";
        std::cin >> br.rating;
        
        if (! std::cin)
            return false;
        
        while (std::cin.get() != '\n')      // clean up the input buffer
            continue;
        
        return true;
    }

    void showBookReview (BookReview& br)
    {
        std::cout << br.rating << "\t\t" << br.title << "\n";
    }
}
