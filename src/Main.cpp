#include "Game.hpp"

#include <docopt/docopt.h>
#include <spdlog/spdlog.h>

#include <cstdlib>
#include <exception>
#include <iterator>
#include <string>

namespace {

constexpr auto usage = R"(
Usage:
    cexpchess
    cexpchess (-h | --help)

Options:
      -h --help     Show this screen.
)";

} // namespace

auto main(const int argc, const char* const* argv) -> int
{
    try {
        spdlog::info("Welcome to cexpchess!");

        [[maybe_unused]] const auto arguments =
            docopt::docopt(usage, {std::next(argv), std::next(argv, argc)});

        constexpr auto board = cexpchess::makeBoard();
        constexpr auto newBoard = cexpchess::move(board, 9, 17);

        std::exit(EXIT_SUCCESS);
    } catch (const std::exception& error) {
        spdlog::error(error.what());
        std::exit(EXIT_FAILURE);
    } catch (...) {
        spdlog::error("unexpected error");
        std::exit(EXIT_FAILURE);
    }
}
