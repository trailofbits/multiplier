# Indexer

The indexer, `mx-index`, is the core workhorse of Multiplier. Its job is to:

 * Receive compile commands from `mx-import`,
 * Build ASTs (using PASTA),
 * Partition those ASTs into fragments,
 * Identify the unique fragments,
 * Label all fragments and contained entities using their unique identifiers,
 * Generate SourceIR for newly discovered unique fragments,
 * Serialize the unique fragments.
 
The indexer is a long-running server that also satisfies queries about the
indexed code. The queries include:

 * Return a list of source file paths and their corresponding file IDs.
 * Return a file's contents and the fragments containing or anchored to that
   file.