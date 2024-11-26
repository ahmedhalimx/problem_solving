#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
	if ((queen_1.row == queen_2.row && queen_1.column == queen_2.column) || 
			(queen_1.row + queen_1.column > 16) ||
			(queen_2.row + queen_2.column > 16))
		return ((attack_status_t){INVALID_POSITION});

	if ((queen_1.row == 0 && queen_1.column == 0) || (queen_2.row == 0 && queen_2.column == 0))
		return ((attack_status_t){INVALID_POSITION});

	if (queen_1.row == queen_2.row || queen_1.column == queen_2.column)
		return ((attack_status_t){CAN_ATTACK});

	if (abs(queen_1.row - queen_2.row) == abs(queen_1.column - queen_2.column))
		return ((attack_status_t){CAN_ATTACK});

	return ((attack_status_t){CAN_NOT_ATTACK});
}
