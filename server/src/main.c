#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include "server.h"
#include "schema.h"
#include "cell_utils.h"


//const int MAX_ROWS = 1000;
const int MAX_ROWS = 100;
const char* db_file_name = "bench.bin";


long get_file_size(const char* filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

int get_memory_usage() {
    FILE* file = fopen("/proc/self/status", "r");

    char buffer[1024] = "";
    int res;

    while (fscanf(file, " %1023s", buffer) == 1) {
        if (strcmp(buffer, "VmSize:") == 0) {
            fscanf(file, " %d", &res);
        }
    }
    fclose(file);

    return res;
}

int main() {
    run_server();

//    printf("Starting tests\n");
//
//    struct StaticFileHeader def_header = createFileHeader(10, 5, 1);
//    FILE* file = fopen("test2.bin", "wb+");
//    writeStaticHeader(file, &def_header);
//
//    // Allocate sector
//    int sectors_needed = (sizeof(struct TableIndexArray) + sizeof(struct SectorHeader) + 100) / SECTOR_SIZE;
//    uint32_t allocated_sector = allocateSector(file, sectors_needed);
//    printf("Allocated from sector %d\n", allocated_sector);
//
//    // Create table index
//    struct TableIndexArray def_table_index;
//    def_table_index.tableMap[0].tableNameHash = 123456;
//    def_table_index.tableMap[0].schemaSector = 12;
//
//    // Write and check
//    writeTableIndexToSector(file, allocated_sector, &def_table_index);
//    struct TableIndexArray test_table_index;
//    readTableIndexFromSector(file, allocated_sector, &test_table_index);
//
//    printf("Test table hash %u\n", test_table_index.tableMap[0].tableNameHash);
//
//    FILE* result_set_file = fopen("./benchmark_results.csv", "w");
//    FILE* fs_burn_file = fopen("../lab_bench_res/fs_burn_test.csv", "w");
//    FILE* database_file = fopen(db_file_name, "wb+");
//
//    fprintf(result_set_file, "Rows,Insertion Time (ms),Deletion time(ms),File Size (bytes),Memory Usage (KB)\n");
//    createFileAndInitEmptyStructure(database_file);
//
//    struct TableScheme table1scheme;
//    initTableScheme(database_file, "table1", 3, &table1scheme);
//    schemaSetColumn(database_file, &table1scheme, 1, TABLE_TYPE_INT, "id");
//    schemaSetColumn(database_file, &table1scheme, 2, TABLE_TYPE_BOOL, "value");
//    schemaSetColumn(database_file, &table1scheme, 3, TABLE_TYPE_VARCHAR, "string");
//
//    int id = 1;
//    bool val = true;
//    char* str = "test_string";
//    union TableCellWithData table1row[table1scheme.columnsCount];
//    rowSetCellValue(database_file, &table1scheme, table1row, 1, TABLE_TYPE_INT, &id);
//    rowSetCellValue(database_file, &table1scheme, table1row, 2, TABLE_TYPE_BOOL, &val);
//    rowSetCellValue(database_file, &table1scheme, table1row, 3, TABLE_TYPE_VARCHAR, str);
//
//    for (int row_num = 1; row_num <= MAX_ROWS; row_num++) {
//        clock_t start, end;
//        double insertion_time, deletion_time;
//        long file_size;
//        int memory_usage;
//
//        file_size = get_file_size(db_file_name);
//        memory_usage = get_memory_usage();
//
//        start = clock();
//        // Insert row into the table
//        addRowToFile(database_file, &table1scheme, table1row);
//        end = clock();
//        insertion_time = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
//
//        start = clock();
//        // Delete same row
//        deleteRowFromFile(database_file, row_num, &table1scheme);
//        end = clock();
//        deletion_time = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
//
//        // Restore row
//        addRowToFile(database_file, &table1scheme, table1row);
//
//        fprintf(result_set_file, "%d,%f,%f,%ld,%d\n", row_num, insertion_time, deletion_time, file_size, memory_usage);
//    }
//
//    printf("Finished tests\n");
//
//    // escape with ctrlc
//    fprintf(fs_burn_file, "File_size, Cycle time\n");
//    srand(time(0));
//    uint32_t count = 1;
//    while (1) {
//        clock_t time_trig = clock();
//        count++;
//        for (int i = 0; i < 900; i++) {
//            if (i < 500) {
//                addRowToFile(database_file, &table1scheme, table1row);
//            }
//            if (i >= 500) {
//                uint32_t lower = 1;
//                uint32_t upper = i + 1;
//                uint32_t rand_row = (rand() % (upper * count - lower + 1)) + lower;
//                deleteRowFromFile(database_file, rand_row, &table1scheme);
//            }
//            if (i % 100 == 0) {
//                fprintf(fs_burn_file, "%ld, %f\n", get_file_size(db_file_name), ((double) (clock() - time_trig)) / CLOCKS_PER_SEC * 1000 );
//                time_trig = clock();
//                fflush(fs_burn_file);
//                printf("write cycle\n");
//            }
//        }
//    }
//
//    fclose(result_set_file);

    return 0;
}
