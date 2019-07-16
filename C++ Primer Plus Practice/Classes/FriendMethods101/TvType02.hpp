//
//  TvType02.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 16/07/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef TvType02_hpp
#define TvType02_hpp

namespace FriendMethods101
{
    class Tv;               // forward declaration
    
    class Remote            // inline methods are defined after Tv class declaration
    {
    public:
        enum {TV, DVD};
        
        Remote(int mode = TV) : mMode(mode) {}
        
        bool volumeUp(Tv& t) const;
        bool volumeDown(Tv& t) const;
        
        void setOnOff(Tv& t) const;
        void channelUp(Tv& t) const;
        void channelDown(Tv& t) const;
        void setMode(Tv& t) const;
        void setInput(Tv& t) const;
        
        void setChannel(Tv& t, int channel) const;
        
    private:
        int mMode;          // controls TV or DVD
    };
    
    class Tv
    {
    public:
        enum {Off, On};
        enum {MinVal, MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};
        
        Tv(int state = Off, int maxChannel = 125)
            : mState (state), mVolume (5), mMaxChannel (maxChannel),
              mChannel (2), mMode (Cable), mInput (TV) {}
        
        void setOnOff() { mState = (mState == On) ? Off : On; } // NB! Can be replaced by `mState ^= 1;`
        
        bool isOn() const { return mState == On; }
        bool volumeUp();
        bool volumeDown();
        
        void channelUp();
        void channelDown();
        void setMode() { mMode = (mMode == Cable) ? Antenna : Cable; }
        void setInput() { mInput = (mInput == TV) ? DVD : TV; }
        
        void showSettings() const;  // display all settings
        
        friend void Remote::setChannel(Tv &t, int channel) const;   // friend member function
        
    private:
        int mState;         // on or off
        int mVolume;        // digitised
        int mMaxChannel;    // max number of channels
        int mChannel;       // current channel
        int mMode;          // broadcast or cable
        int mInput;         // TV or DVD
    };
    
    // Inline definitions for Remote methods
    inline bool Remote::volumeUp(Tv& t) const    { return t.volumeUp(); }
    inline bool Remote::volumeDown(Tv& t) const  { return t.volumeDown(); }
    inline void Remote::setOnOff(Tv& t) const    { t.setOnOff(); }
    inline void Remote::channelUp(Tv& t) const   { t.channelUp(); }
    inline void Remote::channelDown(Tv& t) const { t.channelDown(); }
    inline void Remote::setMode(Tv& t) const     { t.setMode(); }
    inline void Remote::setInput(Tv& t) const    { t.setInput(); }
}   // end namespace FriendClasses101

#endif /* TvType02_hpp */
