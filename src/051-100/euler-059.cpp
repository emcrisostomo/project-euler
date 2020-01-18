#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include "number.h"

void parse_bytes(std::string& line, std::vector<char>& bytes);
void parse_token(const std::string& char_value, std::vector<char>& bytes);
std::vector<std::vector<char>> split_bytes_in_stacks(const std::vector<char>& bytes);

// Each character on a computer is assigned a unique code and the preferred
// standard is ASCII (American Standard Code for Information Interchange).  For
// example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.
//
// A modern encryption method is to take a text file, convert the bytes to
// ASCII, then XOR each byte with a given value, taken from a secret key.  The
// advantage with the XOR function is that using the same encryption key on the
// cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107
// XOR 42 = 65.
//
// For unbreakable encryption, the key is the same length as the plain text
// message, and the key is made up of random bytes.  The user would keep the
// encrypted message and the encryption key in different locations, and without
// both "halves", it is impossible to decrypt the message.
//
// Unfortunately, this method is impractical for most users, so the modified
// method is to use a password as a key.  If the password is shorter than the
// message, which is likely, the key is repeated cyclically throughout the
// message.  The balance for this method is using a sufficiently long password
// key for security, but short enough to be memorable.
//
// Your task has been made easy, as the encryption key consists of three lower
// case characters.  Using p059_cipher.txt, a file containing the encrypted
// ASCII codes, and the knowledge that the plain text must contain common
// English words, decrypt the message and find the sum of the ASCII values in
// the original text.
//
int
main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Invalid number of arguments: " << argc << "\n";
    return 1;
  }

  std::fstream infile(argv[1]);
  std::string line;
  std::vector<char> bytes;

  while (std::getline(infile, line))
  {
    parse_bytes(line, bytes);
  }

  std::vector<std::vector<char>> bytes_stacks = split_bytes_in_stacks(bytes);

  for (auto i = 0; i < 26 * 26 * 26; ++i)
  {
    std::vector<unsigned short> digits = number::get_digits(i, 26);
    digits.resize(3);

    for (const auto& d : digits)
    {
      std::cout << static_cast<char>('a' + d);
    }

    std::cout << '\n';
  }

  std::cout << 0 << '\n';
  return 0;
}

std::vector<std::vector<char>>
split_bytes_in_stacks(const std::vector<char>& bytes)
{
  std::vector<std::vector<char>> stacks(3);

  for (auto v : stacks)
    v.reserve(bytes.size() / 3 + 1);

  for (auto i = 0; i < bytes.size(); ++i)
    stacks[i % 3].push_back(bytes[i]);

  return stacks;
}

void
parse_bytes(std::string& line, std::vector<char>& bytes)
{
  // The line is a comma-separated list of char values.
  const std::string delimiter = ",";
  size_t pos = 0;
  std::string token;

  while ((pos = line.find(delimiter)) != std::string::npos)
  {
    token = line.substr(0, pos);

    parse_token(token, bytes);
    line.erase(0, pos + delimiter.length());
  }

  parse_token(line, bytes);
}

void
parse_token(const std::string& char_value, std::vector<char>& bytes)
{
  bytes.push_back(static_cast<char>(std::stoi(char_value)));
}
