//
//  Worker02.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 02/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Worker02_hpp
#define Worker02_hpp

#include <string>

namespace Inheritance502
{
    class Worker                        // abstract base class
    {
    public:
        Worker() : m_fullName("No one"), m_id(0L) {}
        Worker(const std::string& fullName, long id) : m_fullName(fullName), m_id(id) {}
        
        virtual ~Worker() = 0;          // pure virtual destructor
        virtual void set() = 0;         // don't need to define these in modular approach
        virtual void show() const = 0;  //
        
    protected:
        virtual void data() const;      // helper functions for modular approach
        virtual void get();             //
        
    private:
        std::string m_fullName;
        long m_id;
    };
    
    class Waiter : virtual public Worker
    {
    public:
        Waiter() : Worker(), m_panache(0) {}
        Waiter(const std::string& fullName, long id, int panache = 0)
            : Worker(fullName, id), m_panache(panache) {}
        Waiter(const Worker& w, int panache = 0) : Worker(w), m_panache(panache) {}
        
        virtual void set() override;
        virtual void show() const override;
        
    protected:
        virtual void data() const override;
        virtual void get() override;
        
    private:
        int m_panache;
    };
    
    class Singer : virtual public Worker
    {
    //  TODO: change over to a named enum or enum class
    public:
        Singer() : Worker(), m_voice(other) {}
        Singer(const std::string& fullName, long id, int voice = other)
            : Worker(fullName, id), m_voice(voice) {}
        Singer(const Worker& w, int voice = other) : Worker(w), m_voice(voice) {}
        
        virtual void set() override;
        virtual void show() const override;
        
    protected:
        static const int c_voiceTypes = 7;
        enum {other = 0, alto, contralto, soprano, bass, baritone, tenor};
        
        virtual void data() const override;
        virtual void get() override;
        
    private:
        static const char* s_voiceLabels[c_voiceTypes];     // string equivalents of voice types
        int m_voice;
        
    };
    
    // Multiple inheritance
    class SingingWaiter : public Singer, public Waiter
    {
    public:
        SingingWaiter() {}                  // default ctor - use all default ctors for base classes
        
        // Explicitely calling the virtual base class constructor
        // Base-class parameters for the immidiate parent constructors have to be provided,
        //     despite them not actually calling the virtual base class constructor
        SingingWaiter(const std::string& fullName, long id, int panache = 0, int voice = other)
            : Worker(fullName, id), Waiter(fullName, id, panache), Singer(fullName, id, voice) {}
        SingingWaiter(const Worker& w, int panache = 0, int voice = other)
            : Worker(w), Waiter(w, panache), Singer(w, voice) {}
        SingingWaiter(const Waiter& wt, int voice = other)
            : Worker(wt), Waiter(wt), Singer(wt, voice) {}
        SingingWaiter(const Singer& sn, int panache = 0)
            : Worker(sn), Waiter(sn, panache), Singer(sn) {}
        
        virtual void set() override;            // must override inherited virtual functions
        virtual void show() const override;     //     to avoid ambiguity due to both base classes
                                                //     having methods with the same name
    protected:
        virtual void data() const override;
        virtual void get() override;
    };
    
}   // end namespace Inheritance502

#endif /* Worker02_hpp */
