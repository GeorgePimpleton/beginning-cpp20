module;

#include <cstring>  // For std::strlen() and std::strcpy()

export module message;

#pragma warning(disable : 4996)

export class Message
{
public:
   explicit Message(const char* text = "")
      : m_text(new char[std::strlen(text) + 1]) // Caution: include the null character!
   {
      std::strcpy(m_text, text);        // Mind the order: strcpy(destination, source)!
   }
   ~Message( ) { delete[ ] m_text; }

   Message(const Message& message);            // Copy constructor
   Message& operator=(const Message& message); // Copy assignment operator

   void swap(Message& other) noexcept;

   const char* getText( ) const { return m_text; }

private:
   char* m_text;
};

export void swap(Message& one, Message& other) noexcept
{
   return one.swap(other);
}
