/**
 * @brief It is possible to use more than one parameter in the template header
 * 
 * @description
 * Template header can be modified to take in more than one elements for example
 * 		template <typename T, int extraArgument>
 * Therefore a declaration such as
 * 		Stack <double, 100> myHunderedStack;
 * could be possible. In addition a default parameter can specify a default type.
 * For example:
 * 		template <typename T = string>
 * This makes declarations such as:
 * 		Stack <> jobDescription
 * possible 
 */