 TreeNode node = root;

 while( !parentStack.isEmpty() || node != null){
     if (node != null){
         parentStack.add(node);
         node = node.left;
     } else {
         node = parentStack.pop();
         if (minValue >= node.val){
             isBST = false;
             break;
         } else {
             minValue = node.val;
         }
         node = node.right;
     }
 }

 return isBST;
