#ifndef ODIN_AUDIOEXCEPTION_HPP
#define ODIN_AUDIOEXCEPTION_HPP

#include <exception>
#include <string>
#include <utility>

class AudioException : std::exception {
public:
    /** Constructor (C strings).
     *  @param message C-style string error message.
     *                 The string contents are copied upon construction.
     *                 Hence, responsibility for deleting the char* lies
     *                 with the caller.
     */
    explicit AudioException(const char* message)
            : msg_(message) {}

    /** Constructor (C++ STL strings).
     *  @param message The error message.
     */
    explicit AudioException(std::string  message)
            : msg_(std::move(message)) {}

    /** Destructor.
     * Virtual to allow for subclassing.
     */
    ~AudioException() noexcept override = default;

    /** Returns a pointer to the (constant) error description.
     *  @return A pointer to a const char*. The underlying memory
     *          is in posession of the Exception object. Callers must
     *          not attempt to free the memory.
     */
    [[nodiscard]] const char* what() const noexcept override {
        return msg_.c_str();
    }

protected:
    /** Error message.
     */
    std::string msg_;
};

#endif //ODIN_AUDIOEXCEPTION_HPP
