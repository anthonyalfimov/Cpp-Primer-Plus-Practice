//
//  Worker01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 24/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Worker01_hpp
#define Worker01_hpp

#include <string>

namespace Inheritance501
{
    class Worker                        // abstract base class
    {
    public:
        Worker() : m_fullName("No one"), m_id(0L) {}
        Worker(const std::string& fullName, long id) : m_fullName(fullName), m_id(id) {}
        
        virtual ~Worker() = 0;          // pure virtual destructor
        virtual void set();
        virtual void show() const;
        
    private:
        std::string m_fullName;
        long m_id;
    };
    
    class Waiter : public Worker
    {
    public:
        Waiter() : Worker(), m_panache(0) {}
        Waiter(const std::string& fullName, long id, int panache = 0)
            : Worker(fullName, id), m_panache(panache) {}
        Waiter(const Worker& w, int panache = 0) : Worker(w), m_panache(panache) {}
        
        void set() override;            // not putting `virtual` here is a stylistic choice
        void show() const override;
        
    private:
        int m_panache;
    };
    
    class Singer : public Worker
    {
//  TODO: change over to a named enum or enum class
    public:
        Singer() : Worker(), m_voice(other) {}
        Singer(const std::string& fullName, long id, int voice = other)
            : Worker(fullName, id), m_voice(voice) {}
        Singer(const Worker& w, int voice = other) : Worker(w), m_voice(voice) {}
        
        void set() override;
        void show() const override;
        
    protected:
        static const int c_voiceTypes = 7;
        enum {other = 0, alto, contralto, soprano, bass, baritone, tenor};
        
    private:
        static const char* s_voiceLabels[c_voiceTypes];     // string equivalents of voice types
        int m_voice;
        
    };
}   // end namespace Inheritance501

#endif /* Worker01_hpp */
