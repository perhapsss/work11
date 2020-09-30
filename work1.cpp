class BFS_AI:IEightNumAI 
    {
        Queue<int> queue;
        Dictionary<int, int> CodeSet;
        public AIResult GetAIResult(int begin, int end)
        {
            if (queue == null)
            {
                queue = new Queue<int>(25000);
            }
            if (CodeSet == null)
            {
                CodeSet = new Dictionary<int, int>(181440);
            }
            queue.Enqueue(begin);
            CodeSet.Add(begin, 0);
            AIResult result = new AIResult();
            while (queue.Count > 0)
            {
                int node = queue.Dequeue();
                if (node == end)
                {
                    break;
                }
                for (int i = 1; i <= 4; i++)
                {
                    int child = NumSwitch.GetMoveBorder(node, (Direction)i);
                    if (child != -1 && !CodeSet.ContainsKey(child))
                    {
                        CodeSet.Add(child, node);
                        queue.Enqueue(child);
                    }

                }
            }
            result.path = GetPathFormNode(end);
            result.NodeCount = CodeSet.Count;
            queue.Clear();
            CodeSet.Clear();
            return result;
        }
        private List<Direction> GetPathFormNode(int node)
        {
            List<Direction> path = new List<Direction>();
            int next = CodeSet[node];
            while (next != 0)
            {
                if (node - next == 1)
                {
                    path.Add(Direction.Left);
                }
                else if (node - next == -1)
                {
                    path.Add(Direction.Right);
                }
                else if (node % 10 - next % 10 == -3)
                {
                    path.Add(Direction.Down);
                }
                else if (node % 10 - next % 10 == 3)
                {
                    path.Add(Direction.Up);
                }
                node = next;
                next = CodeSet[next];
            }
            return path;
        }
        public override string ToString()
        {
            return "广度优先搜索算法";
        }
    } 