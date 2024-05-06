/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
using namespace doctest;

const int MIN_TESTS = 20;

int return_code = -1;

struct ReporterCounter : public ConsoleReporter
{
    ReporterCounter(const ContextOptions &input_options)
        : ConsoleReporter(input_options) {}

    void test_run_end(const TestRunStats &run_stats) override
    {
        if (run_stats.numAsserts >= MIN_TESTS)
        {
            return_code = 0;
            std::cout << "the number of tests i have is: " << run_stats.numAsserts << std::endl;
        }
        else
        {
            std::cout << "Please write at least " << MIN_TESTS << " tests! " << std::endl;
            std::cout << "the number of tests I have is: " << run_stats.numAsserts << std::endl;
            return_code = 1;
        }
    }
};

REGISTER_REPORTER("counter", 1, ReporterCounter);

int main(int argc, char **argv)
{
    Context context;
    context.addFilter("reporters", "counter");
    context.run();
    return return_code;
}