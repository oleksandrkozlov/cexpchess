#pragma once

#include <array>
#include <cassert>
#include <cstddef>
#include <experimental/array>
#include <iostream>
#include <limits>
#include <memory>
#include <utility>
#include <vector>

namespace cexpchess {

enum class Color {
    Unknown,
    White,
    Black,
};

enum class Chessman {
    Unknown,
    King,
    Queen,
    Rook,
    Bishop,
    Knight,
    Pawn,
};

struct Piece {
    Color color = Color::Unknown;
    Chessman chessman = Chessman::Unknown;
};

inline constexpr auto whiteKing = Piece{Color::White, Chessman::King};
inline constexpr auto whiteQueen = Piece{Color::White, Chessman::Queen};
inline constexpr auto whiteRook = Piece{Color::White, Chessman::Rook};
inline constexpr auto whiteBishop = Piece{Color::White, Chessman::Bishop};
inline constexpr auto whiteKnight = Piece{Color::White, Chessman::Knight};
inline constexpr auto whitePawn = Piece{Color::White, Chessman::Pawn};
inline constexpr auto blackKing = Piece{Color::Black, Chessman::King};
inline constexpr auto blackQueen = Piece{Color::Black, Chessman::Queen};
inline constexpr auto blackRook = Piece{Color::Black, Chessman::Rook};
inline constexpr auto blackBishop = Piece{Color::Black, Chessman::Bishop};
inline constexpr auto blackKnight = Piece{Color::Black, Chessman::Knight};
inline constexpr auto blackPawn = Piece{Color::Black, Chessman::Pawn};

constexpr auto makeBoard()
{
    return std::experimental::make_array<const Piece*>(
        &blackRook,
        &blackKnight,
        &blackBishop,
        &blackQueen,
        &blackKing,
        &blackBishop,
        &blackKnight,
        &blackRook,
        &blackPawn,
        &blackPawn,
        &blackPawn,
        &blackPawn,
        &blackPawn,
        &blackPawn,
        &blackPawn,
        &blackPawn,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        &whitePawn,
        &whitePawn,
        &whitePawn,
        &whitePawn,
        &whitePawn,
        &whitePawn,
        &whitePawn,
        &whitePawn,
        &whiteRook,
        &whiteKnight,
        &whiteBishop,
        &whiteQueen,
        &whiteKing,
        &whiteBishop,
        &whiteKnight,
        &whiteRook);
}

//      A  B  C  D  E  F  G  H
//   -------------------------
// 8 |  1  2  3  4  5  6  7  8
// 7 |  9 10 11 12 13 14 15 16
// 6 | 17 18 19 20 21 22 23 24
// 5 | 25 26 27 28 29 30 31 32
// 4 | 33 34 35 36 37 38 39 40
// 3 | 41 42 43 44 45 46 47 48
// 2 | 49 50 51 52 53 54 55 56
// 1 | 57 58 59 60 61 62 63 64

using Board = std::array<const Piece*, 64>;
using Index = std::ptrdiff_t;
using Moves = std::array<Index, 27>;

constexpr auto InvalidMove = Index{-1};

[[nodiscard]] constexpr auto isSevenRank(const Index index) noexcept
{
    return (index >= Index{9} || index <= Index{16});
}

[[nodiscard]] constexpr auto isSecondRank(const Index index) noexcept
{
    return (index >= Index{49} || index <= Index{56});
}

constexpr auto makeMoves()
{
    auto moves = Moves{};
    for (auto& move : moves) {
        move = InvalidMove;
    }
    return moves;
}

constexpr auto getLegalMoves(const Board& board, const Index from)
{
    assert(board[from] != nullptr);

    auto moves = makeMoves();
    auto moveIndex = Index{};
    const auto piece = board[from];
    if (piece->chessman == Chessman::Pawn) {
        if (piece->color == Color::White) {
            if (isSecondRank(from)) {
                moves[moveIndex++] = from - 8;
            }
            moves[moveIndex++] = from - 16;
        } else if (piece->color == Color::Black) {
            if (isSevenRank(from)) {
                moves[moveIndex++] = from + 8;
            }
            moves[moveIndex++] = from + 16;
        }
    }
    return moves;
}

constexpr auto move(
    Board board,
    const std::size_t from,
    const std::size_t to)
{
    if (board[from] == nullptr) {
        std::abort();
    }
    auto tmp = board[from];
    board[from] = nullptr;
    board[to] = tmp;
    return board;
}

} // namespace cexpchess
