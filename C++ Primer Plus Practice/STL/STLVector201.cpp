//
//  STLVector201.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 19/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// std::vector iterators, methods, and regular for() loop
//==================================================================================================

#include <iostream>
#include <string>
#include <vector>

namespace
{
    class BookReview
    {
    public:
        bool fill();
        void show() const;
        
    private:
        std::string mTitle;
        int mRating;
    };
}

void showStlVector201()
{
    std::vector<BookReview> bookReviews;        // create an empty vector
    BookReview reviewInput;
    
    while (reviewInput.fill())
        bookReviews.push_back (reviewInput);
    
    int reviewCount = static_cast<int> (bookReviews.size());
    
    if (reviewCount > 0)
    {
        std::cout << "\nThank you. You entered the following:\nRating\tBook\n";
        
        for (int i = 0; i < reviewCount; ++i)
            bookReviews[i].show();
        
        std::cout << "\nReprising:\nRating\tBook\n";
        
        for (std::vector<BookReview>::iterator br = bookReviews.begin(); br != bookReviews.end(); ++br)
            br->show();
        
        std::vector<BookReview> oldBookReviews (bookReviews);       // use copy ctor
        
        if (reviewCount > 3)
        {
            bookReviews.erase(bookReviews.begin() + 1, bookReviews.begin() + 3);    // remove 2 items
            
            std::cout << "\nAfter erasure:\n";
            
            for (auto br = bookReviews.begin(); br != bookReviews.end(); ++br)      // using auto is shorter
                br->show();
            
            bookReviews.insert(bookReviews.begin(), oldBookReviews.begin() + 1,
                               oldBookReviews.begin() + 2);                         // insert 1 item
            
            std::cout << "\nAfter insertion:\n";
            
            for (auto br = bookReviews.begin(); br != bookReviews.end(); ++br)
                br->show();
        }
        
        bookReviews.swap(oldBookReviews);
        
        std::cout << "\nSwapping oldBookReviews with bookReviews:\n";
        
        for (auto br = bookReviews.begin(); br != bookReviews.end(); ++br)
            br->show();
    }
    else
        std::cout << "Nothing entered!\n";
    
    std::cout << "\nDone.\n";
}

namespace
{
    bool BookReview::fill()
    {
        std::cout << "Enter book title (\"quit\" to quit): ";
        std::getline (std::cin, mTitle);
        
        if (mTitle == "quit")
            return false;
        
        std::cout << "Enger book rating: ";
        std::cin >> mRating;
        
        if (! std::cin)
            return false;
        
        while (std::cin.get() != '\n')      // clean up the input buffer
            continue;
        
        return true;
    }

    void BookReview::show() const
    {
        std::cout << mRating << "\t\t" << mTitle << "\n";
    }
}
