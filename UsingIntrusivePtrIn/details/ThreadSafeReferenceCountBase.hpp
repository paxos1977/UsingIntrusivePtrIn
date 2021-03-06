#pragma once
#include <atomic>
#include <cstddef>

namespace UsingIntrusivePtrIn { namespace details {
  
    // multi-threaded base class, for use in <UsingIntrusivePtrIn> mixin.
    struct ThreadSafeReferenceCountBase
    {
        ThreadSafeReferenceCountBase()
            : referenceCount_(0)
        {
        }
        
        ThreadSafeReferenceCountBase(const ThreadSafeReferenceCountBase&)
            : referenceCount_(0)
        {
        }
        
        ThreadSafeReferenceCountBase(ThreadSafeReferenceCountBase&&)
            : referenceCount_(0)
        {
        }
        
        ThreadSafeReferenceCountBase& operator=(const ThreadSafeReferenceCountBase&)
        {
            return *this;
        }
        
        ThreadSafeReferenceCountBase& operator=(ThreadSafeReferenceCountBase&&)
        {
            return *this;
        }
        
        void swap(ThreadSafeReferenceCountBase&)
        {
        }
        
        ~ThreadSafeReferenceCountBase()
        {
        }
        
        mutable std::atomic<std::size_t> referenceCount_;
    };
    
}}
