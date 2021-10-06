#pragma once
#include <vector>
#include <string>

void radixsort(std::vector<std::string> &obj, int size)
{
    int len = obj.size();
    std::vector<std::vector<std::string>> buckets(26);

    auto insertion = [&](int a)
    {
        for (int i = 0; i < len; i++)
        {
            char temp = obj[i][size - 1 - a]; // represents the character at last position in the string
            int index = temp - 'a';           // represents the ascii value starting from 0
            buckets[index].push_back(obj[i]);
        }
    };

    auto removal = [&]()
    {
        obj.clear();
        for (int i = 0; i <= 25; i++)
        {
            for (std::string str : buckets[i])
            {
                obj.push_back(str);
            }
        }
        buckets.clear();
        buckets.resize(26);
    };

    for (int i = 0; i < size; i++)
    {

        insertion(i);
        removal();
    }
};







/*Copyright [2021] [Akki Singh]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */
