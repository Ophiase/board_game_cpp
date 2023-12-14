#pragma once

#include "Combination.hpp"
#include "LootAction.hpp"

class CapturePath {
    private:
        // find a path to capture using only visiteds, starting at axiom    
        bool findCapturePath(
            CellPath &cache, CellPosition capture, Board const & board, 
            CellPath _visiteds = CellPath{}) const;

    public:
        Combination captures;
        Combination visiteds;

        /*
            first visited should always be the beginning of the cellpath
        */
        CapturePath(Combination captures, Combination visiteds) :
        captures{captures}, visiteds{visiteds} {};

        CapturePath(CapturePath const & other) : 
        captures{other.captures}, visiteds{other.visiteds} {};

        CellPath toCellPath(Board const & board) const;
};