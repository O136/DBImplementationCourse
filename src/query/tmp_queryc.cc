#include <iostream>

#include "imlab/database.h"
#include "imlab/infra/hash_table.h"

using namespace imlab;

extern "C" void generated_query(imlab::Database &db) {

	for (const auto &row : db.datastore()->customer_data) {
		auto c_id = row.c_id;

		if (c_id == Integer::build(1)) {
			std::cout 
				<< c_id << " "
				<< std::endl;
		}
	}

}
